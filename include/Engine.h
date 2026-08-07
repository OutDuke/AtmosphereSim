#pragma once
#include "TimeSystem.h"
class Engine{
    private:
        TimeSystem timeSystem;

        bool isRunning;

    public:
        Engine();

        void Run();
};