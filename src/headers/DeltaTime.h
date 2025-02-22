#pragma once
#include <chrono>

class DeltaTime {
public:
    static DeltaTime& getInstance(); //Singleton access
    float getDeltaTime();
    void update();
    
protected:

    std::chrono::high_resolution_clock::time_point lastFrame;
    float deltaTime;

    DeltaTime() = default;
    DeltaTime(const DeltaTime&) = delete;
    DeltaTime& operator=(const DeltaTime&) = delete;
};

extern DeltaTime& dt;