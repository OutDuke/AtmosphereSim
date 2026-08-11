#include "WindSystem.h"

WindSystem::WindSystem()
    : speed(5.0f)
{
}

void WindSystem::Update(int hour)
{
    if (hour >= 0 && hour < 6)
        speed = 5.0f;
    else if (hour < 12)
        speed = 10.0f;
    else
        speed = 15.0f;
}

float WindSystem::GetSpeed() const
{
    return speed;
}