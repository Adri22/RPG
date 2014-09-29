
// #include "SDL.h"
#include "lib/SDL-1.2.15/include/SDL.h"
// #include "lib/SDL2-2.0.3/include/SDL.h"
#include "Singleton.hpp"

#ifndef TIMER_HPP
#define TIMER_HPP

#define g_pTimer CTimer::Get()

class CTimer : public TSingleton<CTimer> {
public:
    CTimer();
    void Update();

    float GetElapsed() {
        return m_fElapsed;
    }

private:
    float m_fElapsed;
    float m_fCurTime;
    float m_fLastTime;
};

#endif
