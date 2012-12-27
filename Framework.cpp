#include "Framework.hpp"

// Init
//
// Aufgabe: Framework initialisieren
//
bool CFramework::Init(	int ScreenWidth, 
						int ScreenHeight,
						int ColorDepth, 
						bool bFullscreen
					  )
{
	// Alle Systeme der SDL initialisieren
	if(SDL_Init (SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1)
	{
		cout << "SDL konnte nicht initialisiert werden!" << endl;
		cout << "Fehlermeldung: " << SDL_GetError() << endl;

		Quit();

		return(false);
	}

	// Vollbild oder Fenstermodus einstellen
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

	// Prüfen, ob alles funktioniert hat
	if(m_pScreen == NULL)
	{
		cout << "Videomodus konnte nicht gesetzt werden!" << endl;
		cout << "Fehlermeldung: " << SDL_GetError() << endl;

		Quit();

		return(false);
	}

	// Zeiger auf internes Array für Tastaturstatus ermitteln
	m_pKeystate = SDL_GetKeyState(NULL);

	// Alles ging glatt, also true zurückliefern
	return(true);
}

// Quit
//
// Aufgabe: Framework (SDL) beenden
//
void CFramework::Quit()
{
	// SDL beenden
	SDL_Quit();
}

// Update
//
// Aufgabe: Timer und Keyboardstatus updaten
//
void CFramework::Update()
{
	// Timer updaten
	g_pTimer->Update();

	// Tastaturstatus ermitteln
	SDL_PumpEvents();
}

// Keydown
//
// Aufgabe: Tastendruck abfragen
//
bool CFramework::KeyDown(int Key_ID)
{
	// Prüfen, ob Taste gedrückt ist
	return(m_pKeystate[Key_ID] ? true : false);
}

// Clear
//
// Aufgabe: Buffer löschen
//
void CFramework::Clear ()
{
	// Buffer (Surface) mit Hintergrundfarbe füllen
	SDL_FillRect(m_pScreen, NULL,
	SDL_MapRGB(m_pScreen->format, 0, 0, 0));
}

// Flip
//
// Aufgabe: Surface umschalten (flippen)
//
void CFramework::Flip()
{
	// Surface umschalten
	SDL_Flip(m_pScreen);
}

