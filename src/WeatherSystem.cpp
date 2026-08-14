#include "WeatherSystem.h"

WeatherSystem::WeatherSystem()
    : currentWeather("Clear")
{
}

void WeatherSystem::Update(float temperature, float humidity, float windSpeed,float cloudDensity)
{
    if (cloudDensity > 80 && windSpeed > 25){
        "Stormy";}
    else if (cloudDensity > 70){
        "Rainy";}
    else if (cloudDensity > 50){
        "Cloudy";}
    else{
        "Sunny";}
}

std::string WeatherSystem::GetWeather() const
{
    return currentWeather;
}