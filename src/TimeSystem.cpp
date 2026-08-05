#include "TimeSystem.h"

TimeSystem::TimeSystem()
    :hour(0)
{
}

void TimeSystem::AdvanceHour(){
    hour++;
    if(hour==24){
        hour = 0;
    }
}

int TimeSystem::GetHour() const{
    return hour;
}