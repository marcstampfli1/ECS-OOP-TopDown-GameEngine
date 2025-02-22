#pragma once
#include "Entity.h"
#include "Components.h"
#include "Systems.h"
#include <memory>


// Base class for behaviors
class EntityBehaviour {
public:
    virtual void update(Entity entity, float dt) = 0;
    virtual ~EntityBehaviour() = default; // Ensure proper cleanup
    virtual void initialize(std::shared_ptr<EntityManager> entityManager);
protected:
    std::shared_ptr<EntityManager> entityManager = nullptr;
};

// Player-specific behavior
class PlayerBehaviour : public EntityBehaviour {
public:
    void update(Entity entity, float dt) override;
};

class EnemyBehaviour : public EntityBehaviour {
public:
    void update(Entity enemy, float dt) override;
};



