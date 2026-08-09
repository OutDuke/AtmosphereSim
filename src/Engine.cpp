#include "Engine.h"
#include "TemperatureSystem.h"

#include <iostream>
#include <thread>
#include <chrono>

Engine::Engine()
    : isRunning(true)
{
}

void Engine::UpdateSystems()
{
    timeSystem.AdvanceHour();

    temperatureSystem.Update(timeSystem, humiditySystem.GetHumidity());
    humiditySystem.Update(timeSystem);
}

void Engine::Run()
{
    std::cout << "Engine Started\n\n";

    while (isRunning)
    {
        UpdateSystems();

        int hour = timeSystem.GetHour();

        std::cout << "Hour: " << hour
                  << " Temp: " << temperatureSystem.GetTemperature()
                  << " Humidity: " << humiditySystem.GetHumidity()
                  << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        if (hour == 10)
        {
            isRunning = false;
        }
    }

    std::cout << "\nEngine Stopped\n";
}