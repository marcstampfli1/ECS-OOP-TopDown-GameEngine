#pragma once

#include "Components.h"
#include "Events.h"
#include "Effects.h"


#include <vector>
#include <memory>
#include <unordered_map>
#include <unordered_set>


class MovementSystem {
public:
    virtual void update(float dt);
    ~MovementSystem() = default;
};

class DamageSystem {
public:    

    //virtual void update();

    void initialize();

    ~DamageSystem() = default;
    
private:

    void applyDamage(const DamageEvent& damageEvent);
};

class StatusSystem {
public:
    void update(float dt);

    ~StatusSystem() = default;
    void initialize();

private: 
    void addStatus(std::shared_ptr<StatusAppliedEvent> status);
    void removeStatus(std::shared_ptr<StatusAppliedEvent> status);
    std::vector<std::shared_ptr<StatusAppliedEvent>> activeStatuses;
    bool isStatusEqual(std::shared_ptr<StatusAppliedEvent> status1, std::shared_ptr<StatusAppliedEvent> status2);

};


class CollisionSystem {
public:
    // Called every frame to check for collisions between entities.
    void update(float dt);

    bool isColliding(Entity a, Entity b) const;

private:
    // Basic AABB collision check between two entities.
    bool checkAABBCollision(Entity a, Entity b);
    bool hasSizeAndPos(Entity entity);
    std::unordered_map<Entity, std::unordered_set<Entity>> currentCollisions;
};
