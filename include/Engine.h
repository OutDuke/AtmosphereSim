#pragma once
#include "TimeSystem.h"
class Engine{
    private:
        TimeSystem timeSystem;
        TemperatureSystem temperatureSystem;

        bool isRunning;

    public:
        Engine();

        void Run();
};