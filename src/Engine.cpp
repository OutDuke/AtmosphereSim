#include "Engine.h"
#include "TemperatureSystem.h"
#include "WindSystem.h"
#include "TimeSystem.h"
#include "CloudSystem.h"

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

Engine::Engine()
    : isRunning(true)
{
}

void Engine::UpdateSystems()
{
    int hour = timeSystem.GetHour();

    windSystem.Update(timeSystem.GetHour());
    humiditySystem.Update(timeSystem);
    temperatureSystem.Update(
        timeSystem,
        humiditySystem.GetHumidity()
    );

    cloudSystem.Update(
    timeSystem,
    humiditySystem.GetHumidity()
    );

    weatherSystem.Update(
        temperatureSystem.GetTemperature(),
        humiditySystem.GetHumidity(),
        windSystem.GetSpeed(),
        cloudSystem.GetCloudDensity()
    );

    // 🔁 Feedback loop
    std::string weather = weatherSystem.GetWeather();

    if (weather == "Strong Storm")
    {
        temperatureSystem.ApplyExternalCooling(3.0f);
        humiditySystem.ReduceHumidity(8.0f);
    }
    else if (weather == "Stormy")
    {
        temperatureSystem.ApplyExternalCooling(2.0f);
        humiditySystem.ReduceHumidity(5.0f);
    }
    else if (weather == "Rainy")
    {
        temperatureSystem.ApplyExternalCooling(1.0f);
        humiditySystem.ReduceHumidity(2.0f);
    }
    
}

void Engine::PrintState() const
{
    std::cout << "Hour: " << timeSystem.GetHour()
              << " Temp: " << temperatureSystem.GetTemperature()
              << " Humidity: " << humiditySystem.GetHumidity()
              << " Wind: " << windSystem.GetSpeed()
              << " Weather: " << weatherSystem.GetWeather()
              << " Clouds: " << cloudSystem.GetCloudDensity()
              << std::endl;
}

void Engine::Run()
{
    while (isRunning)
    {
        PrintState();

        if (timeSystem.GetHour() == 23)  // ✅ check here
        {
            isRunning = false;
            continue;
        }

        UpdateSystems();

        timeSystem.AdvanceHour();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}