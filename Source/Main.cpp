#include "Game.h"

#include <iostream>

#include "Util/Random.h"
/*
#ifdef __WIN32
    extern "C"
    {
        //Enable dedicated graphics
        __declspec(dllexport) bool NvOptimusEnablement = true;
        __declspec(dllexport) bool AmdPowerXpressRequestHighPerformance = true;
    }
#endif // __WIN32
*/
int main()
{
    Game game;
    game.run();
}
