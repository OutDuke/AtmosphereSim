#include <iostream>
#include "TimeSystem.h"
#include "Engine.h"

int main()
{
    Engine engine;

    // Print the raw random initial state (weather might be "Clear" as UpdateSystems hasn't run)
    engine.PrintInitialState();

    engine.Run();
    return 0;
}