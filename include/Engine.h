#pragma once

#include "TimeSystem.h"
#include "TemperatureSystem.h"
#include "HumiditySystem.h"
#include "WeatherSystem.h"
#include "WindSystem.h"

class Engine
{
private:
    TimeSystem timeSystem;
    TemperatureSystem temperatureSystem;
    HumiditySystem humiditySystem;
    WeatherSystem weatherSystem;
    WindSystem windSystem;  
    bool isRunning;

public:
    Engine();
    void Run();
    void UpdateSystems();            
};