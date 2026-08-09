#include "TimeSystem.h"
#pragma once

class TemperatureSystem
{
private:
    float currentTemperature;
    float targetTemperature;
    float changeRate;
public:
    TemperatureSystem();

    void Update(const TimeSystem& timeSystem, float humidity);
    
    float GetTemperature() const;
};