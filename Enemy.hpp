/* 
 * File:   Enemy.h
 * Author: Adrian
 *
 * Created on 23. Dezember 2012, 18:30
 */

#include <string>
#include "Sprite.hpp"

#ifndef ENEMY_H
#define	ENEMY_H

class Enemy 
{
    public:
        Enemy();
        Enemy(const Enemy& orig);
        virtual ~Enemy();
        
		void	Init();
		void	Quit();
		void	Reset();
		void	Render();
		void	Update();
		void	KI();

        float	getHP();
        float	getCurrentHP();

        void	setCurrentHP(float newhp);

    private:
		void				ProcessMoving();
		void				CheckPosition();

		float				xPos;
		float				yPos;
		float				animPhase;

		float				currentHP;

		CSprite				*SpriteEnemy;

		static const float	hp;
		static const long	exp_earn;

};

#endif	/* ENEMY_H */

