#include "headers/DeltaTime.h"
#include <chrono>

DeltaTime& DeltaTime::getInstance() {
    static DeltaTime instance;
    return instance;
}

float DeltaTime::getDeltaTime() {
    return deltaTime;  
}

void DeltaTime::update() {
    std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
    deltaTime = std::chrono::duration<float>(now - lastFrame).count();
    lastFrame = now;  
}

DeltaTime& dt = DeltaTime::getInstance();