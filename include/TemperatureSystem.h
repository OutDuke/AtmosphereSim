#pragma once

class TemperatureSystem
{
private:
    float currentTemperature;
    float targetTemperature;
    float changeRate;
public:
    TemperatureSystem();

    void Update(int hour);
    
    float GetTemperature() const;
};