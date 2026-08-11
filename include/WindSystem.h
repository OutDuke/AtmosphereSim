#pragma once

class WindSystem
{
private:
    float speed;

public:
    WindSystem();

    void Update(int hour);

    float GetSpeed() const;
};