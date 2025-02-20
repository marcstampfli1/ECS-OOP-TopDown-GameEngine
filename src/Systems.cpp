#include "headers/Systems.h"
#include "headers/Entity.h"
#include "headers/Components.h"
#include "headers/ResourceManager.h"
#include "headers/Events.h"
#include <memory>
#include <algorithm>
#include <typeinfo>


extern ResourceManager& rm;

void MovementSystem::update(float dt) {
    for (auto& entity : rm.entityManager.getEntities()) {
        if (rm.positionComponents.find(entity) != rm.positionComponents.end()) {
            rm.positionComponents[entity].x += rm.velocityComponents[entity].vx * dt;
            rm.positionComponents[entity].y += rm.velocityComponents[entity].vy * dt;
        }
    }
}

void DamageSystem::initialize() {
    rm.eventBus.subscribe<DamageEvent>([this](const DamageEvent& damageEvent) {
        (*this).applyDamage(damageEvent);
    });
}

void DamageSystem::applyDamage(const DamageEvent& damageEvent) {
    if (rm.healthComponents.find(damageEvent.target) != rm.healthComponents.end()) {
        rm.healthComponents[damageEvent.target].currentHealth -= damageEvent.damageAmount;
    }
}

void StatusSystem::update(float dt) {

    for (auto it = activeStatuses.begin(); it != activeStatuses.end();) {
        auto& status = *it;
        //if (!(*status).condition()) removeStatus(status);
        (*status).timeSinceLastTick += dt;

        // Apply effect if enough time has passed
        if ((*status).timeSinceLastTick >= (*status).interval) {
            rm.eventBus.publish(DamageEvent((*status).source, (*status).target, 10.0f, EventType::Executable));
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

void StatusSystem::initialize() {
    rm.eventBus.subscribe<StatusAppliedEvent>([this](const StatusAppliedEvent& statusEvent) {
        (*this).addStatus(std::make_shared<StatusAppliedEvent>(statusEvent));
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

/*void applyEnemyTouchStatus(Entity entity) {
    // Check if entity is an enemy
    if (rm.behaviours.find(entity) != rm.behaviours.end() &&
    dynamic_cast<EnemyBehaviour*>(rm.behaviours[entity].get())) {
    
        if (checkAABBCollision(entity, rm.player)) {
            bool effectAlreadyActive = std::any_of(
                rm.statusSystem.activeEffects.begin(),
                rm.statusSystem.activeEffects.end(),
                [entity](const std::shared_ptr<Status>& effect) {
                    return (*effect).source == entity && (*effect).target == rm.player &&
                            dynamic_cast<EnemyTouchingPlayerStatus*>(effect.get()) != nullptr;
                }
            );
            
            if (effectAlreadyActive) {
                return;
            }
            
            rm.statusSystem.addStatus(std::make_unique<EnemyTouchingPlayerStatus>(entity, rm.player, 1.0f, [entity]() -> bool { return checkAABBCollision(entity, rm.player); }, 10)); 
        }
    }
}*/

bool CollisionSystem::checkAABBCollision(Entity a, Entity b) {
    Position posA = rm.positionComponents[a];
    Size sizeA = rm.sizeComponents[a];
    Position posB = rm.positionComponents[b];
    Size sizeB = rm.sizeComponents[b];

    // AABB collision check (assuming top-left origin)
    return (posA.x < posB.x + sizeB.w &&
            posA.x + sizeA.w > posB.x &&
            posA.y < posB.y + sizeB.h &&
            posA.y + sizeA.h > posB.y);
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

    const std::unordered_set<Entity> entities = rm.entityManager.getEntities();

    //check collision between all entities
    for (auto iterator1 = entities.begin(); iterator1 != entities.end(); ++iterator1) {
        for (auto iterator2 = std::next(iterator1); iterator2 != entities.end(); ++iterator2) {
            // Check both entities for size & pos
            if (hasSizeAndPos(*iterator1) && hasSizeAndPos(*iterator2)) {

                if (checkAABBCollision(*iterator1, *iterator2)) {
                    newCollisions[*iterator1].insert(*iterator2);
                    newCollisions[*iterator2].insert(*iterator1);
                }
            }
        }
    }

    for (auto& [entity, newSet] : newCollisions) {
        for (Entity collider : newSet) {
            if (currentCollisions[entity].find(collider) == currentCollisions[entity].end()) {
                rm.eventBus.publish<StatusAppliedEvent>(StatusAppliedEvent(entity, collider, EventType::Touching, 1.0f, [this, entity, collider]() -> bool { return isColliding(entity, collider); }));
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


bool CollisionSystem::hasSizeAndPos(Entity entity) {
    return rm.positionComponents.find(entity) != rm.positionComponents.end() &&
    rm.sizeComponents.find(entity) != rm.sizeComponents.end();
}