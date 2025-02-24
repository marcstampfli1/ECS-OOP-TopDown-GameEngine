#include "headers/Managers.h"
#include "headers/DeltaTime.h"
#include <unordered_set>
#include <iostream>
#include "headers/Behaviours.h"

#include <memory>

void AudioManager::initialize() {
    audioEngine.init();
}

SoLoud::handle AudioManager::playSound(const std::string& name, float volume) {
    if (sounds.find(name) == sounds.end()) {
        std::cerr << "Sound not found: " << name << std::endl;
        return 0; 
    }

    SoLoud::handle activeSound = audioEngine.play(*sounds[name]); 
    audioEngine.setVolume(activeSound, volume);
    return activeSound;
}

void AudioManager::stopSound(SoLoud::handle activeSound) {
    if (audioEngine.isValidVoiceHandle(activeSound)) {
        audioEngine.stop(activeSound);
    }
}

void AudioManager::setVolume(SoLoud::handle activeSound, float volume) {
    if (audioEngine.isValidVoiceHandle(activeSound)) {
        audioEngine.setVolume(activeSound, volume);
    }
}

bool AudioManager::isPlaying(SoLoud::handle activeSound) {
    return audioEngine.isValidVoiceHandle(activeSound);
}

void AudioManager::pauseSound(SoLoud::handle handle) {
    if (audioEngine.isValidVoiceHandle(handle)) {
        audioEngine.setPause(handle, true);
    }
}

void AudioManager::resumeSound(SoLoud::handle handle) {
    if (audioEngine.isValidVoiceHandle(handle)) {
        audioEngine.setPause(handle, false);
    }
}

bool AudioManager::isPaused(SoLoud::handle handle) {
    if (audioEngine.isValidVoiceHandle(handle)) {
        return audioEngine.getPause(handle);
    }
    return false;
}

std::unordered_map<std::string, std::unique_ptr<SoLoud::Wav>>& AudioManager::getAllSounds() {
    return sounds;
}

void SystemManager::update(float dt) {

    movementSystem.update(dt);
    collisionSystem.update(dt);
    statusSystem.update(dt);
}

void SystemManager::initialize(std::shared_ptr<EntityManager> em, std::shared_ptr<EventBus> eb) {
    
    movementSystem.initialize(em, eb);
    collisionSystem.initialize(em, eb);
    statusSystem.initialize(em, eb);

}

Entity EntityManager::createEntity() {
    Entity newEntity = nextEntityID++;
    activeEntities.insert(newEntity);
    return newEntity;
}

void EntityManager::destroyEntity(Entity entity) {
    activeEntities.erase(entity);

    auto typeIterator = typeComponents.find(entity);
    if (typeIterator != typeComponents.end()) {
        EntityType entityType = typeIterator->second;
        if (auto iterator = activeEntitiesByType.find(entityType); iterator != activeEntitiesByType.end()) {
            iterator->second.erase(entity);
            if (iterator->second.empty()) {
                activeEntitiesByType.erase(iterator);
            }
        }
        typeComponents.erase(typeIterator);
    }

    behaviours.erase(entity);

    sizeComponents.erase(entity);
    
    positionComponents.erase(entity);
    
    velocityComponents.erase(entity);
}

bool EntityManager::entityExists(Entity entity) const {
    return activeEntities.find(entity) != activeEntities.end();
}

const std::unordered_set<Entity>& EntityManager::getEntitiesByType(EntityType type) const {
    static const std::unordered_set<Entity> emptySet;
    if (activeEntitiesByType.count(type) > 0) {
        return activeEntitiesByType.at(type);
    }
    
    return emptySet;
}


const std::unordered_set<Entity>& EntityManager::getAllEntities() const {
    return activeEntities;
}
    
void EntityManager::setType(Entity entity, EntityType type) {
    typeComponents[entity] = type;
    activeEntitiesByType[type].insert(entity);
}

const EntityType* EntityManager::getType(Entity entity) {
    if (typeComponents.count(entity) > 0) {
        return &typeComponents.at(entity);
    }
    return nullptr;
}

void EntityManager::setBehaviour(Entity entity, std::shared_ptr<EntityBehaviour> behaviour) {
    behaviour->initialize(getSharedPtr());
    behaviours[entity] = std::move(behaviour);
}

const std::shared_ptr<EntityBehaviour> EntityManager::getBehaviour(Entity entity) {
    if (behaviours.count(entity) > 0) {
        return behaviours.at(entity);
    }
    return nullptr;
}

void EntityManager::setSize(Entity entity, const Size& size) {
    sizeComponents[entity] = size;
}

const Size* EntityManager::getSize(Entity entity) {
    if (sizeComponents.count(entity) > 0) {
        return &sizeComponents.at(entity);
    }
    return nullptr; 
}

void EntityManager::setPlayer(Entity entity) {
    player = entity;
}

Entity EntityManager::getPlayer() {
    return player;
}

Position* EntityManager::getPosition(Entity entity) {
    if (positionComponents.count(entity) > 0) {
        return &positionComponents.at(entity);
    }
    return nullptr;
}

Velocity* EntityManager::getVelocity(Entity entity) {
    if (velocityComponents.count(entity)) {
        return &velocityComponents.at(entity);
    }
    return nullptr;
    
}

void EntityManager::setPosition(Entity entity, const Position& pos) {
    positionComponents[entity] = pos; 
}

void EntityManager::setVelocity(Entity entity, const Velocity& vel) {
    velocityComponents[entity] = vel; 
}

/*void RenderManager::testFunction() {

    beginDraw();
    endDraw();

}*/