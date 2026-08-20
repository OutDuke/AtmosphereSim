#include"TemperatureSystem.h"
#include "TimeSystem.h"
#include <random>

TemperatureSystem::TemperatureSystem()
{
    static std::random_device rd;
    static std::mt19937 generator(rd());
    std::uniform_real_distribution<float> distribution(10.0f, 30.0f);

    currentTemperature = distribution(generator);
    targetTemperature = currentTemperature;
    changeRate = 0.02f;
}

void TemperatureSystem::Update(const TimeSystem& timeSystem, float humidity)
{
    int hour = timeSystem.GetHour();

    if (hour >= 0 && hour < 6)
        targetTemperature = 15.0f;
    else if (hour >= 6 && hour < 12)
        targetTemperature = 25.0f;
    else if (hour >= 12 && hour < 16)
        targetTemperature = 30.0f;
    else if (hour >= 16 && hour < 21)
        targetTemperature = 22.0f;
    else
        targetTemperature = 18.0f;

    // 🔥 NEW: humidity influence
    targetTemperature -= (humidity - 50.0f) * 0.01f;

    float humidityEffect = (humidity - 50.0f) * 0.01f;
    targetTemperature -= humidityEffect;

    float diff = targetTemperature - currentTemperature;
    currentTemperature += diff * 0.02f;

    currentTemperature = std::max(0.0f, std::min(50.0f, currentTemperature));
    
}

float TemperatureSystem::GetTemperature() const
{
    return currentTemperature;
}

void TemperatureSystem::ApplyExternalCooling(float amount)
{
    currentTemperature -= amount;
}