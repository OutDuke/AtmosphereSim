#include"TemperatureSystem.h"

TemperatureSystem::TemperatureSystem()
{
    currentTemperature = 20.0;
    targetTemperature = 20.0;
    changeRate = 0.0;
}

void TemperatureSystem::Update(int hour)
{
    if(hour == 0)
        if (hour >= 0 && hour < 6)
    {
        targetTemperature = 15.0f;
    }
    else if (hour >= 6 && hour < 12)
    {
        targetTemperature = 25.0f;
    }
    else if (hour >= 12 && hour < 16)
    {
        targetTemperature = 30.0f;
    }
    else if (hour >= 16 && hour < 21)
    {
        targetTemperature = 22.0f;
    }
    else
    {
        targetTemperature = 18.0f;
    }
    currentTemperature += (targetTemperature - currentTemperature) * changeRate;
}

float TemperatureSystem::GetTemperature() const
{
    return currentTemperature;
}