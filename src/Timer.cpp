#include "Timer.hpp"

CTimer::CTimer() {
	m_fCurTime = 0.0f;
	m_fLastTime = SDL_GetTicks() / 1000.0f;
	m_fElapsed = 0.0f;
}

void CTimer::Update() {
	m_fCurTime = SDL_GetTicks() / 1000.0f;

	m_fElapsed = m_fCurTime - m_fLastTime;
	m_fLastTime = m_fCurTime;
}
