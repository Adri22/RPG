#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "Framework.hpp"

class CSprite
{
	public:
		CSprite();
		~CSprite();

		void Load			(const string sFilename);
		void Load			(	const string sFilename, 
								int NumFrames,
								int FrameWidth, 
								int FrameHeight
							);
		void SetColorKey	(int R, int G, int B);
		void SetPos			(float fXPos, float fYPos);
		void Render			();
		void Render			(float fFrameNumber);
		SDL_Rect GetRect	() 
		{
			return m_Rect;
		}

	private:
		SDL_Surface *m_pScreen; 
		SDL_Surface *m_pImage;  
		SDL_Rect m_Rect;        
		SDL_Rect m_FrameRect;   
		int m_NumFrames;        
		int m_FrameWidth;       
		int m_FrameHeight;      
		int m_NumFramesX;       
};

#endif
