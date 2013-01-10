/* 
 * File:   Game.h
 * Author: Adrian
 *
 * Created on 23. Dezember 2012, 18:38
 */

#include <list>
#include "Player.hpp"
#include "Enemy.hpp"

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
		void		getFPS			();
		void		ProcessEvents   ();
		void		SpawnEnemys		();
		void		HandleEnemys	();
		void		CheckCollisions	();
 
		Player				*player;             // Player-Instance
		CSprite				*SpriteBackground;   
		bool				gameRun;             // Is the game still running?
		int					frameCount;
		float				frameTimer;
		float				spawnTimer;
		list<Enemy*>		EnemyList;		     // A list, full of enemys
};

#endif	/* GAME_H */

