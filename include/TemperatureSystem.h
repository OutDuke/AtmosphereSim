#pragma once

#include "TimeSystem.h"   // ✅ REQUIRED

class TemperatureSystem
{
private:
    float currentTemperature;
    float targetTemperature;
    float changeRate;

public:
    TemperatureSystem();

    void Update(const TimeSystem& timeSystem,float humidity);  // ✅ must match
    float GetTemperature() const;

    void ApplyExternalCooling(float amount);
};