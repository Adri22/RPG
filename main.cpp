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
#include "SDL.h"
#include "Player.hpp"
#include "Framework.hpp"

using namespace std;

int main(int argc, char** argv) 
{
    g_pLogfile->CreateLogfile("log.html");
    g_pLogfile->Textout("Programm gestartet", true);
    
	g_pLogfile->Textout("Framework initialisieren ...", true);
	if(g_pFramework->Init(800, 600, 16, false) == false)
	{
		g_pLogfile->Textout("Framework initialisieren fehlgeschlagen", true);
		return (0);
	}
	else
		g_pLogfile->Textout("Framework initialisiert", true);
		



	// TEST
	//
	Player pl;

	pl.setName("Test");
	pl.displayStats();

	// EXP-TEST
	//
	// pl.setEXP(150000);
	// pl.displayStats();




	g_pLogfile->Textout("Framework beenden ...", true);
	g_pFramework->Quit();
	g_pFramework->Del();

    g_pLogfile->Textout("Programm beendet", true);
    g_pLogfile->Del();
    
    return 0;
}

