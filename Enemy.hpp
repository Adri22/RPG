/* 
 * File:   Enemy.h
 * Author: Adrian
 *
 * Created on 23. Dezember 2012, 18:30
 */

#include <string>
#include <list>
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

        float	getHP();
        float	getCurrentHP();

		bool	getHit();
		void	setHit(bool hit);

		void	setCurrentHP(float newhp);

		struct				hitbox
		{
			int		width;
			int		height;
			int		left;
			int		right;
			int		top;
			int		bottom;
		}					enemy;

		struct				attackbox
		{
			float	atkXpos;
			float	atkYpos;
			int		width;
			int		height;
			int		left;
			int		right;
			int		top;
			int		bottom;
		}					enemy_atk_box;

    private:
		void				ProcessMoving();
		void				CheckPosition();
		void				KI();
		void				AtkBoxPositioning();
		void				updateHitbox();

		float				xPos;
		float				yPos;
		float				animPhase;

		float				currentHP;
		bool				isHit;

		CSprite				*SpriteEnemy;

		static const float	hp;
		static const long	exp_earn;

};

#endif	/* ENEMY_H */

