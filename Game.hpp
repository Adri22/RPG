/* 
 * File:   Game.h
 * Author: Adrian
 *
 * Created on 23. Dezember 2012, 18:38
 */

#include "Player.hpp"

#ifndef GAME_H
#define	GAME_H

class Game 
{
    public:
        Game();
        Game(const Game& orig);
        virtual ~Game();

		void Init	();
		void Run	();
		void Quit	();

    private:
		void		ProcessEvents   ();

		Player		*player;             // Player-Instance
		CSprite		*SpriteBackground;   
		bool		gameRun;             // Is the game still running?
};

#endif	/* GAME_H */

