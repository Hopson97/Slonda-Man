#include "Game.h"

#include <iostream>

#include "Util/Random.h"

#ifdef __WIN32
    extern "C"
    {
        //Enable dedicated graphics
        __declspec(dllexport) bool NvOptimusEnablement = true;
        __declspec(dllexport) bool AmdPowerXpressRequestHighPerformance = true;
    }

    #define _WIN32_WINNT 0x0500
    #include <windows.h>
#endif // __WIN32


int main()
{
    #ifdef __WIN32
    HWND consoleWindow = GetConsoleWindow();
    SetWindowPos( consoleWindow, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
    #endif // __WIN32
    Game game;
    game.run();
}
