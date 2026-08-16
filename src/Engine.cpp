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

// Print the current state (used each loop iteration)
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

// Print the *initial* randomized state (no automatic UpdateSystems() call).
// If you prefer the "computed initial state" (after systems apply one update/feedback pass),
// call UpdateSystems() before calling PrintInitialState() from main().
void Engine::PrintInitialState() const
{
    std::cout << "=== INITIAL STATE ===\n";
    std::cout << "Hour: " << timeSystem.GetHour()
              << " Temp: " << temperatureSystem.GetTemperature()
              << " Humidity: " << humiditySystem.GetHumidity()
              << " Wind: " << windSystem.GetSpeed()
              << " Clouds: " << cloudSystem.GetCloudDensity()
              << " Weather: " << weatherSystem.GetWeather()
              << "\n=====================\n";
}

void Engine::Run()
{
    while (isRunning)
    {
        UpdateSystems();

        PrintState();

        if (timeSystem.GetHour() == 23)
        {
            isRunning = false;
            continue;
        }

        timeSystem.AdvanceHour();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}