#include "HumiditySystem.h"

HumiditySystem::HumiditySystem()
{
    currentHumidity = 50.0f;
    targetHumidity = 50.0f;
    changeRate = 0.1f;
}

void HumiditySystem::Update(const TimeSystem& timeSystem)
{
    int hour = timeSystem.GetHour();

    if (hour >= 0 && hour < 6)
        targetHumidity = 80.0f;
    else if (hour >= 6 && hour < 12)
        targetHumidity = 60.0f;
    else if (hour >= 12 && hour < 16)
        targetHumidity = 40.0f;
    else
        targetHumidity = 55.0f;

    currentHumidity += (targetHumidity - currentHumidity) * changeRate;
}

float HumiditySystem::GetHumidity() const
{
    return currentHumidity;
}