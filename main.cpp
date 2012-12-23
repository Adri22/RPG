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
#include <unistd.h>
#include "Log.h"
#include "Random.h"
#include "sdl/sdl.h"

using namespace std;

int main(int argc, char** argv) 
{
    g_pLogfile->CreateLogfile("log.html");
    g_pLogfile->Textout("Programm gestartet", true);
    
    
    g_pLogfile->Textout("Programm beendet", false);
    g_pLogfile->Del();
    
    return 0;
}

