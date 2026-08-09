#pragma once

#include "TimeSystem.h"

class HumiditySystem
{
private:
    float currentHumidity;
    float targetHumidity;
    float changeRate;

public:
    HumiditySystem();

    void Update(const TimeSystem& timeSystem);
    float GetHumidity() const;
};