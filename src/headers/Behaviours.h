#pragma once

#include "Entity.h"
#include "Components.h"
#include "Systems.h"

#include <memory>

class EntityBehaviour {
public:
    virtual void update(Entity entity, float dt) = 0;
    virtual ~EntityBehaviour() = default; // Ensure proper cleanup
    virtual void initialize(std::shared_ptr<EntityManager> em); 

protected:
    std::shared_ptr<EntityManager> entityManager = nullptr;
};




