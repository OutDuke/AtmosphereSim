#include "WeatherSystem.h"

WeatherSystem::WeatherSystem()
    : currentWeather("Clear")
{
}

void WeatherSystem::Update(float temperature, float humidity, float windSpeed)
{
    if (humidity > 70 && windSpeed > 30)
        currentWeather = "Strong Storm";
    else if (humidity > 70 && windSpeed > 20)
        currentWeather = "Stormy";
    else if (humidity > 65)
        currentWeather = "Rainy";
    else if (humidity > 50)
        currentWeather = "Cloudy";
    else
        currentWeather = "Sunny";
}

std::string WeatherSystem::GetWeather() const
{
    return currentWeather;
}