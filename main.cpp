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

    //Start SDL.
    SDL_Init( SDL_INIT_EVERYTHING );
    screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );
   
    //Draw a rectangle to the screen.
    SDL_Rect rect = {10,10,10,10};
    SDL_FillRect(screen, &rect, 0xFF0000);
    SDL_Flip(screen);

    //Admire your handiwork for 5 seconds.
    SDL_Delay(50000);
   
    //Quit SDL
    SDL_Quit();
    
    g_pLogfile->Textout("Programm beendet", false);
    g_pLogfile->Del();
    
    return 0;
}

