#include <iostream>
#include "TimeSystem.h"

int main(){

    TimeSystem time;
    std::cout << time.GetHour() << std::endl;
    time.AdvanceHour();
    std::cout << time.GetHour() << std::endl;
    time.AdvanceHour();
    std::cout << time.GetHour() << std::endl;

    return 0;
}
