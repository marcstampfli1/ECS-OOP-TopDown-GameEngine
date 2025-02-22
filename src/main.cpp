#include "headers/Behaviours.h"
#include "headers/Components.h"
#include "headers/Entity.h"
#include "headers/Systems.h"
#include "headers/Managers.h"
#include "headers/DeltaTime.h"
#include "headers/Events.h"

#include "../graphicslib/src/Window.h" 
#include "../graphicslib/src/Shader.h" 
#include "../graphicslib/src/Mesh.h" 
#include "../graphicslib/src/Texture.h"

#include <iostream>
#include <vector>

void gameLoop(std::shared_ptr<EventBus> eventBus, std::shared_ptr<EntityManager> entityManager, std::shared_ptr<SystemManager> systemManager, std::shared_ptr<Renderer> renderer);

int main() {

    std::shared_ptr<EventBus> eventBus = std::make_shared<EventBus>();
    std::shared_ptr<EntityManager> entityManager = std::make_shared<EntityManager>();
    std::shared_ptr<SystemManager> systemManager = std::make_shared<SystemManager>();
    std::shared_ptr<Renderer> renderer = std::make_shared<Renderer>();

    Entity player = entityManager->createEntity();
    Entity enemy = entityManager->createEntity();  
    
    entityManager->setPosition(player,  { 0, 0 });
    entityManager->setPosition(enemy,  { 200, 200 });

    entityManager->setVelocity(player,  { 0, 0 });
    entityManager->setVelocity(enemy,  { 0, 0 });

    entityManager->setHealth(player,  { 100, 100 });
    entityManager->setHealth(enemy,  { 100, 100 });

    entityManager->setType(player, EntityType::PLAYER);
    entityManager->setType(enemy, EntityType::ENEMY);

    entityManager->setSize(player, { 50, 50 });
    entityManager->setSize(enemy, { 50, 50 });

    entityManager->setBehaviour(player, std::make_shared<PlayerBehaviour>());
    entityManager->setBehaviour(enemy, std::make_shared<EnemyBehaviour>());

    entityManager->setPlayer(player);

    systemManager->initialize(entityManager, eventBus);
    renderer->initialize(entityManager);
    
    Window& window = renderer->getWindow();

    renderer->getWindow().updateFunction = [eventBus, entityManager, systemManager, renderer]() {
        gameLoop(eventBus, entityManager, systemManager, renderer);
    };
    
    window.run();

    std::cin.get();

    window.close();

    return 0;
}

void gameLoop(std::shared_ptr<EventBus> eventBus, std::shared_ptr<EntityManager> entityManager, std::shared_ptr<SystemManager> systemManager, std::shared_ptr<Renderer> renderer) {
    renderer->render();
    DeltaTime::getInstance().update();
    systemManager->update(DeltaTime::getInstance().getDeltaTime());
    for (Entity entity : entityManager->getAllEntities()) {
        entityManager->getBehaviour(entity)->update(entity, dt.getDeltaTime());
    }
}






