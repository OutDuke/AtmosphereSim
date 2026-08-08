#include "Engine.h"
#include "TemperatureSystem.h"

#include <iostream>
#include <thread>
#include <chrono>

Engine::Engine()
    : isRunning(true)
{
}

void Engine::Run()
{
    std::cout << "Engine Started\n\n";

    while (isRunning)
    {
        int hour = timeSystem.GetHour();

        // Update systems
        temperatureSystem.Update(hour);

        // Print state
        std::cout << "Hour: " << hour
                  << " Temp: " << temperatureSystem.GetTemperature()
                  << std::endl;

        // Advance time
        timeSystem.AdvanceHour();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        if (timeSystem.GetHour() == 10)
        {
            isRunning = false;
        }
    }

    std::cout << "\nEngine Stopped\n";
}