#pragma once

#include "TimeSystem.h"
#include "TemperatureSystem.h"
#include "HumiditySystem.h"
#include "WeatherSystem.h"
#include "WindSystem.h"
#include "CloudSystem.h"

class Engine
{
private:
    TimeSystem timeSystem;
    TemperatureSystem temperatureSystem;
    HumiditySystem humiditySystem;
    WeatherSystem weatherSystem;
    WindSystem windSystem;  
    CloudSystem cloudSystem;
    bool isRunning;

public:
    Engine();
    void Run();
    void UpdateSystems();
    void PrintState() const;
    void PrintInitialState() const;   // <-- new
};