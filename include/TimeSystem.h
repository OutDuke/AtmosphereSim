#pragma once
class TimeSystem{
    private:
        int hour;
    public:
        TimeSystem();
        void AdvanceHour();
        int GetHour() const;
        void Update(const TimeSystem& timeSystem);
};