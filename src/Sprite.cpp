#include "Sprite.hpp"

CSprite::CSprite() {
	screen = g_pFramework->GetScreen();
	renderer = g_pFramework->GetRenderer();
}

CSprite::~CSprite() {
	SDL_FreeSurface(m_pImage);
}

void CSprite::Load(const string sFilename) {
	m_pImage = SDL_LoadBMP(sFilename.c_str());

	if (m_pImage == NULL) {
		cout << "Error while loading: " << sFilename.c_str() << endl;
		cout << "Error: " << SDL_GetError() << endl;

		g_pFramework->Quit();
		exit(1);
	}

	m_Rect.x = 0;
	m_Rect.y = 0;
	m_Rect.w = m_pImage->w;
	m_Rect.h = m_pImage->h;
}

void CSprite::Load(const string sFilename, int NumFrames, int FrameWidth,
		int FrameHeight) {
	Load(sFilename);
	m_NumFrames = NumFrames;
	m_FrameWidth = FrameWidth;
	m_FrameHeight = FrameHeight;
	m_FrameRect.w = FrameWidth;
	m_FrameRect.h = FrameHeight;
	m_NumFramesX = m_pImage->w / m_FrameWidth;
}

void CSprite::SetColorKey(int R, int G, int B) {
	SDL_SetColorKey(m_pImage, SDL_SRCCOLORKEY,
			SDL_MapRGB(m_pImage->format, R, G, B));
}

void CSprite::SetPos(float fXPos, float fYPos) {
	m_Rect.x = static_cast<int>(fXPos);
	m_Rect.y = static_cast<int>(fYPos);
}

void CSprite::Render() {
	SDL_BlitSurface(m_pImage, NULL, screen, &m_Rect);
}

void CSprite::Render(float fFrameNumber) {
	int Column = static_cast<int>(fFrameNumber) % m_NumFramesX;
	int Row = static_cast<int>(fFrameNumber) / m_NumFramesX;

	m_FrameRect.x = Column * m_FrameWidth;
	m_FrameRect.y = Row * m_FrameHeight;

	SDL_BlitSurface(m_pImage, &m_FrameRect, screen, &m_Rect);
}
