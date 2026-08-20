#include "CloudSystem.h"

CloudSystem::CloudSystem()
{
    cloudDensity = 30.0f;
}

void CloudSystem::Update(const TimeSystem& timeSystem, float humidity)
{
    int hour = timeSystem.GetHour();

    // base from humidity
    cloudDensity += (humidity - 50.0f) * 0.02f;

    // slight variation with time
    if (hour >= 18 || hour <= 6)
        cloudDensity += 1.0f; // more clouds at night
    else
        cloudDensity -= 0.5f;

    // clamp
    if (cloudDensity < 0) cloudDensity = 0;
    if (cloudDensity > 100) cloudDensity = 100;
}

float CloudSystem::GetCloudDensity() const
{
    return cloudDensity;
}