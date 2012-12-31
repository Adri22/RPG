
#include "Log.hpp"
#include "Sprite.hpp"

CSprite::CSprite()
{
	// point to screen
	m_pScreen = g_pFramework->GetScreen();
}

CSprite::~CSprite()
{
	SDL_FreeSurface(m_pImage);
}

// Load
//
void CSprite::Load(const string sFilename)
{
	// load Bitmap
	m_pImage = SDL_LoadBMP(sFilename.c_str());

	// NULL-Check
	if(m_pImage == NULL)
	{
		g_pLogfile->Textout("Fehler beim Laden der Grafik: ", false);
		g_pLogfile->Textout(sFilename.c_str(), true);

		cout << "Fehler beim Laden von: " << sFilename.c_str() << endl;
		cout << "Fehlermeldung: " << SDL_GetError() << endl;

		// delete framework
		g_pFramework->Quit();

		// exit game 
		exit(1);
	}

	// initialize rect
	m_Rect.x = 0;
	m_Rect.y = 0;
	m_Rect.w = m_pImage->w;
	m_Rect.h = m_pImage->h;
}

// Load animate sprite
//
void CSprite::Load(	const string sFilename, 
					int NumFrames,
					int FrameWidth, 
					int FrameHeight
				   )
{
	// load function
	Load(sFilename);

	m_NumFrames   = NumFrames;
	m_FrameWidth  = FrameWidth;
	m_FrameHeight = FrameHeight;
	m_FrameRect.w = FrameWidth;
	m_FrameRect.h = FrameHeight;
	m_NumFramesX  = m_pImage->w / m_FrameWidth;
}

// SetColorKey - set transparent color
//
void CSprite::SetColorKey(int R, int G, int B)
{
	SDL_SetColorKey(	m_pImage, SDL_SRCCOLORKEY,
						SDL_MapRGB(m_pImage->format, R, G, B) 
				    );
}

// SetPos
//
void CSprite::SetPos(float fXPos, float fYPos)
{
	cout << "setpos " << fXPos << " " << fYPos << endl;

	// update rect
	m_Rect.x = static_cast<int>(fXPos);
	m_Rect.y = static_cast<int>(fYPos);
}

// Render
//
void CSprite::Render()
{
	SDL_BlitSurface(m_pImage, NULL, m_pScreen, &m_Rect);
}

// Render animated sprite
//
void CSprite::Render(float fFrameNumber)
{
	// define column
	int Column = static_cast<int>(fFrameNumber) % m_NumFramesX;

	// define row
	int Row = static_cast<int>(fFrameNumber) / m_NumFramesX;

	m_FrameRect.x = Column * m_FrameWidth;
	m_FrameRect.y = Row * m_FrameHeight;

	SDL_BlitSurface(m_pImage, &m_FrameRect, m_pScreen, &m_Rect);
}
