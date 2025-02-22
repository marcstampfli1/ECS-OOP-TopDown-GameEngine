#include "headers/Behaviours.h"
#include "headers/Entity.h"
#include "headers/Components.h"
#include "headers/Systems.h"
#include "headers/Managers.h"

#include <windows.h>
#include <iostream>
#include <cmath>

void PlayerBehaviour::update(Entity entity, float dt) {
    
    Velocity* entityVelocity = entityManager->getVelocity(entity);
    
    if (!entityVelocity) {
        return;
    }

    float speed = 180.0f;
    float xSpeed = 0.0f;
    float ySpeed = 0.0f;

    entityManager->getVelocity(entity)->vx = 0; 
    entityManager->getVelocity(entity)->vy = 0;

    if (GetAsyncKeyState('W')) ySpeed = -speed;
    if (GetAsyncKeyState('A')) xSpeed = -speed;
    if (GetAsyncKeyState('S')) ySpeed = speed;
    if (GetAsyncKeyState('D')) xSpeed = speed;

    float vectorLength = std::sqrt(xSpeed * xSpeed + ySpeed * ySpeed);
    if (vectorLength > 0.01f) {
        entityVelocity->vx = xSpeed / vectorLength * speed;
        entityVelocity->vy = ySpeed / vectorLength * speed;
    } 
    
}

void EnemyBehaviour::update(Entity enemy, float dt) {
    
    Velocity* enemyVelocity = entityManager->getVelocity(enemy);
    Position* enemyPosition = entityManager->getPosition(enemy);

    Velocity* playerVelocity = entityManager->getVelocity(entityManager->getPlayer());
    Position* playerPosition = entityManager->getPosition(entityManager->getPlayer());

    if (!enemyVelocity || !enemyPosition || !playerVelocity || !playerPosition) {
        return;
    }

    float speed = 100.0f;

    
    float xDistance = playerPosition->x - enemyPosition->x;
    float yDistance = playerPosition->y - enemyPosition->y;

    float vectorLength = std::sqrt(xDistance * xDistance + yDistance * yDistance);

    if (vectorLength > 0.1f) {
        float normX = xDistance / vectorLength; // Normalize x
        float normY = yDistance / vectorLength; // Normalize y
        
        // Apply velocity in the direction of the player
        enemyVelocity->vx = normX * speed;
        enemyVelocity->vy = normY * speed;
    } else {
        enemyVelocity->vx = 0; 
        enemyVelocity->vy = 0;
    }
    
}  

void EntityBehaviour::initialize(std::shared_ptr<EntityManager> em) {
    entityManager = em;
}

