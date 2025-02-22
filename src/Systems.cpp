#include "headers/Systems.h"
#include "headers/Entity.h"
#include "headers/Components.h"
#include "headers/Managers.h"
#include "headers/Events.h"

#include <memory>
#include <algorithm>
#include <typeinfo>



void MovementSystem::update(float dt) {
    for (auto& entity : entityManager->getAllEntities()) {
        if (entityManager->getPosition(entity)) {
            entityManager->getPosition(entity)->x += entityManager->getVelocity(entity)->vx * dt;
            entityManager->getPosition(entity)->y += entityManager->getVelocity(entity)->vy * dt;
        }
    }
}

void MovementSystem::initialize(std::shared_ptr<EntityManager> em) {
    entityManager = em;
}

void DamageSystem::initialize(std::shared_ptr<EntityManager> em, std::shared_ptr<EventBus> eb) {
    entityManager = em;
    eventBus = eb;
    eventBus->subscribe<DamageEvent>([this](const DamageEvent& damageEvent) {
        this->applyDamage(damageEvent);
    });
}

void DamageSystem::applyDamage(const DamageEvent& damageEvent) {
    Health* entityHealth = entityManager->getHealth(damageEvent.target);
    if (!entityHealth) return;

    entityHealth->currentHealth -= damageEvent.damageAmount;
    
}

void DamageSystem::update(float dt) {
    return;
}

void StatusSystem::update(float dt) {

    for (auto it = activeStatuses.begin(); it != activeStatuses.end();) {
        auto& status = *it;
        (*status).timeSinceLastTick += dt;

        // Apply effect if enough time has passed
        if ((*status).timeSinceLastTick >= (*status).interval) {
            eventBus->publish(DamageEvent((*status).source, (*status).target, 10.0f, EventType::Executable));
            (*status).timeSinceLastTick = 0; // Reset timer
        }

        // Remove effect if expired
        if (!(*status).condition()) {
            it = activeStatuses.erase(it);
        } else {
            ++it;
        }
    }
}

void StatusSystem::initialize(std::shared_ptr<EventBus> eb) {
    eventBus = eb;
    eventBus->subscribe<StatusAppliedEvent>([this](const StatusAppliedEvent& statusEvent) {
        this->addStatus(std::make_shared<StatusAppliedEvent>(statusEvent));
    });
}

void StatusSystem::addStatus(std::shared_ptr<StatusAppliedEvent> status) {
    activeStatuses.push_back(std::move(status));
}

bool StatusSystem::isStatusEqual(std::shared_ptr<StatusAppliedEvent> status1, std::shared_ptr<StatusAppliedEvent> status2) {
    return status1 == status2;
}

void StatusSystem::removeStatus(std::shared_ptr<StatusAppliedEvent> status) {
    auto it = std::remove_if(activeStatuses.begin(), activeStatuses.end(),
        [this, &status](const std::shared_ptr<StatusAppliedEvent>& s) {
            return isStatusEqual(s, status);
        });
    activeStatuses.erase(it, activeStatuses.end());
}

void CollisionSystem::initialize(std::shared_ptr<EntityManager> em, std::shared_ptr<EventBus> eb) {
    entityManager = em;
    eventBus = eb;
}


bool CollisionSystem::checkAABBCollision(Entity entity1, Entity entity2) {

    const Position* posA = entityManager->getPosition(entity1);
    const Size* sizeA = entityManager->getSize(entity1);
    const Position* posB = entityManager->getPosition(entity2);
    const Size* sizeB = entityManager->getSize(entity2);

    if (!posA || !sizeA || !posB || !sizeB) return false;

    // AABB collision check (assuming top-left origin)
    return (posA->x < posB->x + sizeB->w &&
            posA->x + sizeA->w > posB->x &&
            posA->y < posB->y + sizeB->h &&
            posA->y + sizeA->h > posB->y);
}

bool CollisionSystem::isColliding(Entity firstEntity, Entity secondEntity) const {
    //stores iterator of firstEntity
    auto iterator = currentCollisions.find(firstEntity);

    if (iterator != currentCollisions.end()) {
        return (*iterator).second.find(secondEntity) != (*iterator).second.end(); //checks if the secondEntity is in the set of touchingEntities
    }
    return false;
}

void CollisionSystem::update(float dt) {
    // Temporary map to hold new collision states
    std::unordered_map<Entity, std::unordered_set<Entity>> newCollisions;

    const std::unordered_set<Entity> entities = entityManager->getAllEntities();

    //check collision between all entities
    for (auto iterator1 = entities.begin(); iterator1 != entities.end(); ++iterator1) {
        for (auto iterator2 = std::next(iterator1); iterator2 != entities.end(); ++iterator2) {
            // Check both entities for size & pos
            
            if (checkAABBCollision(*iterator1, *iterator2)) {
                newCollisions[*iterator1].insert(*iterator2);
                newCollisions[*iterator2].insert(*iterator1);
            }
        }
    }

    for (auto& [entity, newSet] : newCollisions) {
        for (Entity collider : newSet) {
            if (currentCollisions[entity].find(collider) == currentCollisions[entity].end()) {
                eventBus->publish<StatusAppliedEvent>(StatusAppliedEvent(entity, collider, EventType::Touching, 1.0f, [this, entity, collider]() -> bool { return isColliding(entity, collider); }));
            }
        }
    }

    for (auto& [entity, oldSet] : currentCollisions) {
        for (Entity collider : oldSet) {
            if (newCollisions[entity].find(collider) == newCollisions[entity].end()) {
                //publish event
            }
        }
    }

    currentCollisions = std::move(newCollisions);
}

