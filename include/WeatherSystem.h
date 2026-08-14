#pragma once
#include <string>

class WeatherSystem
{
private:
    std::string currentWeather;

public:
    WeatherSystem();

    void Update(float temperature, float humidity, float windSpeed,float cloudDensity);

    std::string GetWeather() const;
};