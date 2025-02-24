#pragma once

#include "Components.h"
#include "Events.h"

#include <vector>
#include <memory>
#include <unordered_map>
#include <unordered_set>

class EntityManager;
class EventBus;

class System {
public:
    virtual void update(float dt) = 0;
    virtual ~System() = default;
    virtual void initialize(std::shared_ptr<EntityManager> em, std::shared_ptr<EventBus> eb); 
protected:
    std::shared_ptr<EntityManager> entityManager = nullptr;
    std::shared_ptr<EventBus> eventBus = nullptr;
};

class MovementSystem : public System {
public:
    void update(float dt) override;
    ~MovementSystem() = default;
};

class StatusSystem : public System {
public:
    void update(float dt) override;
    void initialize(std::shared_ptr<EntityManager> em, std::shared_ptr<EventBus> eb) override;
    const std::vector<std::shared_ptr<StatusAppliedEvent>>& getActiveStatuses() const;
    ~StatusSystem() = default;

protected: 

    void addStatus(std::shared_ptr<StatusAppliedEvent> status);
    void removeStatus(std::shared_ptr<StatusAppliedEvent> status);
    std::vector<std::shared_ptr<StatusAppliedEvent>> activeStatuses;
    bool isStatusEqual(std::shared_ptr<StatusAppliedEvent> status1, std::shared_ptr<StatusAppliedEvent> status2);

};


class CollisionSystem : public System {
public:
    // Called every frame to check for collisions between entities.
    void update(float dt) override;
    
    bool isColliding(Entity a, Entity b) const;
    const std::unordered_map<Entity, std::unordered_set<Entity>>& getCollisions();

protected:
    // Basic AABB collision check between two entities.
    bool checkAABBCollision(Entity entity1, Entity entity2);
    std::unordered_map<Entity, std::unordered_set<Entity>> currentCollisions;
    std::unordered_map<Entity, std::unordered_set<Entity>> newCollisions;
    std::unordered_map<Entity, std::unordered_set<Entity>> endedCollisions;
};
