/* 
 * File:   main.cpp
 * Author: Adrian
 *
 * Created on 14. Dezember 2012, 00:27
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <windows.h>
#include "Log.hpp"
#include "Random.hpp"
#include "sdl.h"

using namespace std;

int main(int argc, char** argv) 
{
    g_pLogfile->CreateLogfile("log.html");
    g_pLogfile->Textout("Programm gestartet", true);
    
	SDL_Surface* screen = NULL;

    SDL_Init( SDL_INIT_EVERYTHING );
    screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );
   
    SDL_Rect rect = {50,50,10,10};
    SDL_FillRect(screen, &rect, 0xFF0000);
    SDL_Flip(screen);

    SDL_Delay(10000);
   
    SDL_Quit();
    
    g_pLogfile->Textout("Programm beendet", false);
    g_pLogfile->Del();
    
    return 0;
}

