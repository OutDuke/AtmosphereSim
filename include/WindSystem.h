#pragma once

class WindSystem
{
private:
    float speed;
    float targetSpeed;
    float changeRate;

public:
    WindSystem();

    void Update(int hour);

    float GetSpeed() const;
};