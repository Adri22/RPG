#include "Framework.hpp"

// Init framework
//
bool CFramework::Init(	int ScreenWidth, 
						int ScreenHeight,
						int ColorDepth, 
						bool bFullscreen
					  )
{
	if(SDL_Init (SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1)
	{
		cout << "SDL konnte nicht initialisiert werden!" << endl;
		cout << "Fehlermeldung: " << SDL_GetError() << endl;

		Quit();

		return(false);
	}

	// fullscreen or window?
	if(bFullscreen == true)
	{
		m_pScreen = SDL_SetVideoMode(	ScreenWidth, 
										ScreenHeight, 
										ColorDepth,
										SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN
									);
	}
	else
	{
		m_pScreen = SDL_SetVideoMode(	ScreenWidth, 
										ScreenHeight, 
										ColorDepth,
										SDL_HWSURFACE | SDL_DOUBLEBUF
									);
	}

	// everything allright?
	if(m_pScreen == NULL)
	{
		cout << "Videomodus konnte nicht gesetzt werden!" << endl;
		cout << "Fehlermeldung: " << SDL_GetError() << endl;

		Quit();

		return(false);
	}

	// point to internal keystate-array
	m_pKeystate = SDL_GetKeyState(NULL);

	return(true);
}

// Quit
//
void CFramework::Quit()
{
	SDL_Quit();
}

// Update
//
void CFramework::Update()
{
	// update timer
	g_pTimer->Update();

	// detection current keystates
	SDL_PumpEvents();
}

// Keydown
//
bool CFramework::KeyDown(int Key_ID)
{
	return(m_pKeystate[Key_ID] ? true : false);
}

// Clear buffer
//
void CFramework::Clear ()
{
	SDL_FillRect(m_pScreen, NULL,
	SDL_MapRGB(m_pScreen->format, 0, 0, 0));
}

// Flip
//
void CFramework::Flip()
{
	SDL_Flip(m_pScreen);
}

