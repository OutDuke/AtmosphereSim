#pragma once

#include "TimeSystem.h"
#include "TemperatureSystem.h"

class Engine
{
private:
    TimeSystem timeSystem;
    TemperatureSystem temperatureSystem;
    bool isRunning;

public:
    Engine();
    void Run();
};