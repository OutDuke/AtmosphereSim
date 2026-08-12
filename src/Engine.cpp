#include "Engine.h"
#include "TemperatureSystem.h"
#include "WindSystem.h"

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
    timeSystem.AdvanceHour();
    temperatureSystem.Update(timeSystem, humiditySystem.GetHumidity());
    humiditySystem.Update(timeSystem);
    weatherSystem.Update(
        temperatureSystem.GetTemperature(),
        humiditySystem.GetHumidity(),
        windSystem.GetSpeed()
    );
    windSystem.Update(timeSystem.GetHour());
}

void Engine::Run()
{
    std::cout << "Engine Started\n\n";

    while (isRunning)
    {
        UpdateSystems();

        int hour = timeSystem.GetHour();

        std::string weather;

        float humidity = humiditySystem.GetHumidity();

        if (humidity > 65)
            weather = "Rainy";
        else if (humidity > 45)
            weather = "Cloudy";
        else
            weather = "Sunny";

        std::cout << "Hour: " << hour
                  << " Temp: " << temperatureSystem.GetTemperature()
                  << " Humidity: " << humiditySystem.GetHumidity()
                  << " Weather: " << weatherSystem.GetWeather()
                  << " Wind: " << windSystem.GetSpeed()
                  << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        if (hour == 10)
        {
            isRunning = false;
        }
    }

    std::cout << "\nEngine Stopped\n";
}