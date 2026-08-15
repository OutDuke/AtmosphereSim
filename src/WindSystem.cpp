#include "WindSystem.h"
#include <random>

WindSystem::WindSystem()
{
    static std::random_device rd;
    static std::mt19937 generator(rd());
    std::uniform_real_distribution<float> distribution(5.0f, 35.0f);

    speed = distribution(generator);
    targetSpeed = speed;
    changeRate = 0.1f;
}

void WindSystem::Update(int hour)
{
    if (hour >= 0 && hour < 6)
        targetSpeed = 5.0f;
    else if (hour < 12)
        targetSpeed = 10.0f;
    else
        targetSpeed = 15.0f;

    speed += (targetSpeed - speed) * changeRate;
}

float WindSystem::GetSpeed() const
{
    return speed;
}