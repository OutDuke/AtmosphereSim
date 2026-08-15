#include "HumiditySystem.h"
#include <random>

HumiditySystem::HumiditySystem()
{
    static std::random_device rd;
    static std::mt19937 generator(rd());
    std::uniform_real_distribution<float> distribution(40.0f, 90.0f);

    currentHumidity = distribution(generator);
    targetHumidity = currentHumidity;
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

void HumiditySystem::ReduceHumidity(float amount)
{
    float minHumidity = 30.0f;  // natural lower bound

    currentHumidity -= amount;

    if (currentHumidity < minHumidity)
        currentHumidity = minHumidity;
}