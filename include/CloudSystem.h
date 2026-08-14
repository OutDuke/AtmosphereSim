#pragma once

#include "TimeSystem.h"

class CloudSystem
{
private:
    float cloudDensity; // 0 to 100

public:
    CloudSystem();

    void Update(const TimeSystem& timeSystem, float humidity);

    float GetCloudDensity() const;
};