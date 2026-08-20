#include "WeatherSystem.h"

WeatherSystem::WeatherSystem(){
    currentWeather = "Cloudy";
}

void WeatherSystem::Update(float temperature, float humidity, float windSpeed, float cloudDensity)
{
    if (currentWeather == "Stormy")
    {
        if (cloudDensity < 70 || windSpeed < 20)
            currentWeather = "Rainy";
    }
    else if (currentWeather == "Rainy")
    {
        if (cloudDensity > 85 && windSpeed > 25)
            currentWeather = "Stormy";
        else if (cloudDensity < 60 && humidity < 65)
            currentWeather = "Cloudy";
    }
    else if (currentWeather == "Cloudy")
    {
        if (cloudDensity > 75 && humidity > 70)
            currentWeather = "Rainy";
        else if (cloudDensity < 40)
            currentWeather = "Sunny";
    }
    else if (currentWeather == "Sunny" || currentWeather == "Clear")
    {
        if (cloudDensity > 50)
            currentWeather = "Cloudy";
    }
}

std::string WeatherSystem::GetWeather() const
{
    return currentWeather;
}