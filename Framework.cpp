
#include "Framework.hpp"

bool CFramework::Init(
        int ScreenWidth,
        int ScreenHeight,
        int ColorDepth,
        bool bFullscreen
        ) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1) {
        cout << "Could not initialize SDL" << endl;
        cout << "Error: " << SDL_GetError() << endl;

        Quit();

        return (false);
    }

    if (bFullscreen == true) {
        m_pScreen = SDL_SetVideoMode(
                ScreenWidth,
                ScreenHeight,
                ColorDepth,
                SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN
                );
    } else {
        m_pScreen = SDL_SetVideoMode(
                ScreenWidth,
                ScreenHeight,
                ColorDepth,
                SDL_HWSURFACE | SDL_DOUBLEBUF
                );
    }

    if (m_pScreen == NULL) {
        cout << "Error: " << SDL_GetError() << endl;

        Quit();

        return (false);
    }

    m_pKeystate = SDL_GetKeyState(NULL);

    return (true);
}

void CFramework::Quit() {
    SDL_Quit();
}

void CFramework::Update() {
    // update timer
    g_pTimer->Update();
    SDL_PumpEvents();
}

bool CFramework::KeyDown(int Key_ID) {
    return (m_pKeystate[Key_ID] ? true : false);
}

void CFramework::Clear() {
    SDL_FillRect(m_pScreen, NULL,
            SDL_MapRGB(m_pScreen->format, 0, 0, 0));
}

void CFramework::Flip() {
    SDL_Flip(m_pScreen);
}

