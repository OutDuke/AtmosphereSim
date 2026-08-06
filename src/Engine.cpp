#include<iostream>
#include "Engine.h"

void Engine::Run(){
    std::cout << "Engine Started\n\n" << std::endl;

    for(int i = 0;i < 10;i++){
        std::cout << "Hour: " << timeSystem.GetHour() << std::endl;
        timeSystem.AdvanceHour();
    }
}
