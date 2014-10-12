#include <cstdlib>
#include <iostream>
#include "Framework.hpp"
#include "Game.hpp"

using namespace std;

int main(int argc, char** argv) {

	g_pFramework->Init(800, 600);

	g_pGame->Init();
	g_pGame->Run();
	g_pGame->Quit();
	g_pGame->Del();

	g_pFramework->Quit();
	g_pFramework->Del();

	return 0;
}

