#pragma once

#include "Components.h"
#include "Events.h"

#include <vector>
#include <memory>
#include <unordered_map>
#include <unordered_set>

class EntityManager;
class EventBus;

class MovementSystem {
public:
    void initialize(std::shared_ptr<EntityManager> entityManager);
    void update(float dt);
    ~MovementSystem() = default;

protected:
    std::shared_ptr<EntityManager> entityManager = nullptr;
};

class DamageSystem {
public:

    void initialize(std::shared_ptr<EntityManager> entityManager, std::shared_ptr<EventBus> eventBus);    
    void update(float dt);

    void initialize();
    void applyDamage(const DamageEvent& damageEvent);

    ~DamageSystem() = default;
    
protected:

    std::shared_ptr<EventBus> eventBus = nullptr;
    std::shared_ptr<EntityManager> entityManager = nullptr;

};

class StatusSystem {
public:
    void update(float dt);

    ~StatusSystem() = default;
    void initialize(std::shared_ptr<EventBus> eventBus);

protected: 
    std::shared_ptr<EventBus> eventBus = nullptr;

    void addStatus(std::shared_ptr<StatusAppliedEvent> status);
    void removeStatus(std::shared_ptr<StatusAppliedEvent> status);
    std::vector<std::shared_ptr<StatusAppliedEvent>> activeStatuses;
    bool isStatusEqual(std::shared_ptr<StatusAppliedEvent> status1, std::shared_ptr<StatusAppliedEvent> status2);

};


class CollisionSystem {
public:
    // Called every frame to check for collisions between entities.
    void update(float dt);
    void initialize(std::shared_ptr<EntityManager> entityManager, std::shared_ptr<EventBus> eventBus);
    
    bool isColliding(Entity a, Entity b) const;

protected:
    // Basic AABB collision check between two entities.
    bool checkAABBCollision(Entity entity1, Entity entity2);
    std::unordered_map<Entity, std::unordered_set<Entity>> currentCollisions;

    std::shared_ptr<EventBus> eventBus = nullptr;
    std::shared_ptr<EntityManager> entityManager = nullptr;
};
