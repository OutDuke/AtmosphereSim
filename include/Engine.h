#pragma once

#include "TimeSystem.h"
#include "TemperatureSystem.h"
#include "HumiditySystem.h"

class Engine
{
private:
    TimeSystem timeSystem;
    TemperatureSystem temperatureSystem;
    HumiditySystem humiditySystem;   
    bool isRunning;

public:
    Engine();
    void Run();
    void UpdateSystems();            
};