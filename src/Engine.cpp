#include<iostream>
#include "Engine.h"
#include<thread>
#include<chrono>

Engine::Engine()
    : isRunning(true)
{
}

void Engine::Run()
{
    std::cout << "Engine Started\n\n";

    while(isRunning)
    {
        std::cout << "Hour: "
                  << timeSystem.GetHour()
                  << std::endl;

        timeSystem.AdvanceHour();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        if(timeSystem.GetHour() == 10)
        {
            isRunning = false;
        }

        std::cout << "\nEngine Stopped\n";
    }
}
