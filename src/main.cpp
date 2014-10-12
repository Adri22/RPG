
#include <cstdlib>
#include <iostream>
#include <SDL.h>
#include "Log.hpp"
#include "Framework.hpp"
#include "Game.hpp"

using namespace std;

int main(int argc, char** argv) {
    g_pLogfile->CreateLogfile("log.html");
    g_pLogfile->Textout("programm started", true);

    g_pLogfile->Textout("Initialize framework ...", true);
    if (g_pFramework->Init(800, 600, 16, false) == false) {
        g_pLogfile->Textout("Framework initialize failed", true);
        return (0);
    } else {
    	g_pLogfile->Textout("Framework initialized", true);
    }

    g_pGame->Init();
    g_pGame->Run();
    g_pGame->Quit();
    g_pGame->Del();

    g_pFramework->Quit();
    g_pFramework->Del();

    g_pLogfile->Textout("exit", true);
    g_pLogfile->Del();

    return 0;
}

