#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <iostream>
#include "Singleton.hpp"
#include "Timer.hpp"

using namespace std;

#define g_pFramework CFramework::Get()

class CFramework: public TSingleton<CFramework> {
public:
	bool Init(int ScreenWidth, int ScreenHeight);
	void Quit();
	void Update();
	void Clear();
	void Flip();
	bool KeyDown(int Key_ID);

	SDL_Window *GetScreen() {
		return screen;
	}
	SDL_Renderer *GetRenderer() {
		return renderer;
	}

private:
	SDL_Window *screen; // Screen-Surface
	SDL_Renderer *renderer;
	Uint8 *keystate; // Keystate-Array
};

#endif
