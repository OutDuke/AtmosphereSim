#include "WeatherSystem.h"

WeatherSystem::WeatherSystem()
    : currentWeather("Clear")
{
}

void WeatherSystem::Update(float temperature, float humidity, float windSpeed, float cloudDensity)
{
    if (cloudDensity > 80 && windSpeed > 25)
    {
        currentWeather = "Stormy";
    }
    else if (cloudDensity > 70)
    {
        currentWeather = "Rainy";
    }
    else if (cloudDensity > 50)
    {
        currentWeather = "Cloudy";
    }
    else
    {
        currentWeather = "Sunny";
    }
}

std::string WeatherSystem::GetWeather() const
{
    return currentWeather;
}