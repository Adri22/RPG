#include "Framework.hpp"

bool CFramework::Init(int ScreenWidth, int ScreenHeight) {

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1) {
		cout << "Could not initialize SDL" << endl;
		cout << "Error: " << SDL_GetError() << endl;
		Quit();
		return (false);
	}

	SDL_CreateWindowAndRenderer(ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN,
			&screen, &renderer);

	if (screen == NULL) {
		cout << "Error: " << SDL_GetError() << endl;
		Quit();
		return (false);
	}

	// keystate = SDL_GetKeyState(NULL);

	return (true);
}

void CFramework::Quit() {
	SDL_Quit();
}

void CFramework::Update() {
	g_pTimer->Update();
	SDL_PumpEvents();
}

bool CFramework::KeyDown(int Key_ID) {
	return (keystate[Key_ID] ? true : false);
}

void CFramework::Clear() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void CFramework::Flip() {
	SDL_RenderPresent(renderer);
}

