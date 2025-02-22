#include "headers/Managers.h"
#include "headers/DeltaTime.h"
#include <unordered_set>
#include <iostream>
#include "headers/Behaviours.h"

#include <memory>

void SystemManager::update(float dt) {
    movementSystem.update(dt);
    collisionSystem.update(dt);
    statusSystem.update(dt);
    damageSystem.update(dt);
}

void SystemManager::initialize(std::shared_ptr<EntityManager> em, std::shared_ptr<EventBus> eb) {

    movementSystem.initialize(em);
    collisionSystem.initialize(em, eb);
    statusSystem.initialize(eb);
    damageSystem.initialize(em, eb);

}

void Renderer::initialize(std::shared_ptr<EntityManager> em) {

    entityManager = em;

    window.open(1200, 800, "Window");

    window.initializeOpenGL();
    shaders["default"] = std::make_shared<Shader>("../graphicslib/shaders/texture/vertex.glsl", "../graphicslib/shaders/texture/fragment.glsl");

    window.setFramerate(120);

    glClearColor(0.3f, 0.5f, 0.1f, 1.0f);
    
    std::cout << "Initialised Window" << std::endl;

    textures["player"] = std::make_shared<Texture>("../assets/textures/person.jpg");
    textures["default"] = std::make_shared<Texture>("../assets/textures/person.jpg");

    std::cout << "Loaded Shader and texture" << std::endl;

    for (auto& enemy : entityManager->getEntitiesByType(EntityType::ENEMY)) {
        textureComponents[enemy] = textures["player"].get();
    }

    textureComponents[entityManager->getPlayer()] = textures["player"].get();
   
}

void Renderer::updateEntityRectangles() {
    for (const Entity& entity : entityManager->getAllEntities()) {

        const Size* entitySize = entityManager->getSize(entity);
        const Position* entityPosition = entityManager->getPosition(entity);

        if(!entitySize) {
            continue;
        }

        if(!entityPosition) {
            continue;
        }

      
        if (meshComponents.find(entity) == meshComponents.end()) {
            meshComponents[entity] = std::make_unique<Mesh>(*createRectangle());
        }

        Mesh* mesh = meshComponents[entity].get();  // Get the existing mesh

        // Update shader uniforms
        if (shaderComponents.find(entity) != shaderComponents.end()) {
            mesh->getUniforms(shaderComponents[entity]->shaderProgram);
        } else {
            mesh->getUniforms(shaders["default"]->shaderProgram);
        }

        // Update mesh position & size
        float* pos = window.toOpenGLCoordinates(
            entityPosition->x + entitySize->w / 2, 
            entityPosition->y + entitySize->h / 2
        );

        mesh->x = pos[0];
        mesh->y = pos[1];
        delete[] pos;


        float* size = window.toOpenGLSize(
            entitySize->w, 
            entitySize->h
        );

        mesh->w = size[0];
        mesh->h = size[1];
        delete[] size;

        // Update transformation matrices
        mesh->updateModelMatrix();
        mesh->loadModelMatrix();
    }  
}

void Renderer::render() {
    updateEntityRectangles();
    glClear(GL_COLOR_BUFFER_BIT);
    sortEntitiesByYValue();

    float deltaTime = dt.getDeltaTime();

    for (auto entity : sortedDrawEntities) {
        if (textureComponents.find(entity) != textureComponents.end()) {
            textureComponents[entity]->bind(0);
        } else {
            textures["default"]->bind(0);
        }

        if (shaderComponents.find(entity) != shaderComponents.end()) {
            shaderComponents[entity]->use();
            glUniform1i(glGetUniformLocation(shaderComponents[entity]->shaderProgram, "tex"), 0);
        } else {
            shaders["default"]->use();
            glUniform1i(glGetUniformLocation(shaders["default"]->shaderProgram, "tex"), 0);
        }
        
        meshComponents[entity]->updateModelMatrix();
        meshComponents[entity]->loadModelMatrix();
        meshComponents[entity]->draw();
    }
}

void Renderer::sortEntitiesByYValue() {
    sortedDrawEntities.clear();

    for (auto& entity : entityManager->getAllEntities()) {
        sortedDrawEntities.push_back(entity);
    }
    std::stable_sort(sortedDrawEntities.begin(), sortedDrawEntities.end(), 
        [this](Entity a, Entity b) {
            return entityManager->getPosition(a)->y < entityManager->getPosition(b)->y;
        }
    );
}

Window& Renderer::getWindow() {
    return window;
}

Entity EntityManager::createEntity() {
    Entity newEntity = nextEntityID++;
    activeEntities.insert(newEntity);
    return newEntity;
}

void EntityManager::destroyEntity(Entity entity) {
    activeEntities.erase(entity);
}

bool EntityManager::entityExists(Entity entity) const {
    return activeEntities.find(entity) != activeEntities.end();
}

const std::unordered_set<Entity> EntityManager::getEntitiesByType(EntityType type) const {
    return activeEntitiesByType.at(type);
}


const std::unordered_set<Entity> EntityManager::getAllEntities() const {
    return activeEntities;
}
    
void EntityManager::setType(Entity entity, EntityType type) {
    activeEntitiesByType[type].insert(entity);
    typeComponents[entity] = type;
}

const EntityType* EntityManager::getType(Entity entity) {
    if (typeComponents.find(entity) == typeComponents.end()) {
        return &typeComponents.at(entity);
    }
    return nullptr;
}

void EntityManager::setBehaviour(Entity entity, std::shared_ptr<EntityBehaviour> behaviour) {
    behaviour->initialize(getSharedPtr());
    behaviours[entity] = std::move(behaviour);
}

const std::shared_ptr<EntityBehaviour> EntityManager::getBehaviour(Entity entity) {
    if (behaviours.find(entity) != behaviours.end()) {
        return behaviours.at(entity);
    }
    return nullptr;
}

void EntityManager::setSize(Entity entity, const Size& size) {
    sizeComponents[entity] = size;
}

const Size* EntityManager::getSize(Entity entity) {
    if (sizeComponents.find(entity) == sizeComponents.end()) {
        return nullptr; 
    }
    return &sizeComponents.at(entity);
}

void EntityManager::setPlayer(Entity entity) {
    player = entity;
}

Entity EntityManager::getPlayer() {
    return player;
}

Position* EntityManager::getPosition(Entity entity) {
    if (positionComponents.find(entity) == positionComponents.end()) {
        return nullptr;
    }

    return &positionComponents.at(entity);
}

Velocity* EntityManager::getVelocity(Entity entity) {
    if (velocityComponents.find(entity) == velocityComponents.end()) {
        return nullptr;
    }

    return &velocityComponents.at(entity);
}

Health* EntityManager::getHealth(Entity entity) {
    if (healthComponents.find(entity) == healthComponents.end()) {
        return nullptr;
    }

    return &healthComponents.at(entity);
}

void EntityManager::setPosition(Entity entity, const Position& pos) {
    positionComponents[entity] = pos; 
}

void EntityManager::setVelocity(Entity entity, const Velocity& vel) {
    velocityComponents[entity] = vel; 
}

void EntityManager::setHealth(Entity entity, const Health& health) {
    healthComponents[entity] = health; 
}