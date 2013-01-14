/* 
 * File:   Player.h
 * Author: Adrian
 *
 * Created on 15. Dezember 2012, 17:47
 */

#include <string>
#include <list>
#include "Singleton.hpp"
#include "Sprite.hpp"
#include "Combat.hpp"

#ifndef PLAYER_H
#define	PLAYER_H

using namespace std;

#define g_pPlayer Player::Get()

enum DIRECTIONS
{
    UP,
    DOWN, 
    LEFT, 
    RIGHT
};

class Player : public TSingleton<Player>
{
    public:
        Player();
        Player(const Player& orig);
        virtual ~Player();
        
		void	Init();
		void	Quit();
		void	Reset();
		void	Render();
		void	Update();

        string	getName();
        float	getHP();
		float	getDMG();
		float	getSpeed();
		float	getHPreg();
        int		getStr();
        int		getVita();
        int		getDex();
        int		getSpirit();
        int		getLevel();
		float	getCurrentHP();
		int		getDirection();

        void setName(string name);
        void setHP(float hp);
		void setDMG(float dmg);
		void setSpeed(float speed);
		void setHPreg(float hpReg);
        void setStr(int str);
        void setVita(int vita);
        void setDex(int dex);
        void setSpirit(int spirit);
		void setLevel(int level);
        void setCurrentHP(float newhp);

		void setEXP(long exp_gained);
		void levelUp();
		void chooseStatPoint();
		void displayStats();

		list<int>	getHitboxPositions();
		list<int>	getAtkboxPositions();

		struct				hitbox
		{
			int width;
			int height;
		}					player;

		struct				attackbox
		{
			float	atkXpos;
			float	atkYpos;
			int		width;
			int		height;
		}					player_atk_box;

    private:
		void				ProcessMoving();
		void				Attacking();
		void				CheckPosition();
		void				AtkBoxPositioning();

		float				calcHP();
		float				calcDMG();
		float				calcSpeed();
		float				calcHPreg();

		list<int>			hitboxPositions;
		list<int>			atkboxPositions;
		bool				attack_processed;
		float				xPos;
		float				yPos;
		float				animPhase;
		float				currentHP;
        float				hp;
		float				dmg;
		float				speed;
		float				hpReg;
        int					str;
        int					vita;
        int					dex;
        int					spirit;
		int					level;
		long				exp;
		int					currentDirection;
		bool				diagonal_moving;

		string				name;
		CSprite				*SpritePlayer;

		static const int	maxLevel;
		static const long	exp_base;
		static const long	exp_step;
		static const float	vita_hp_factor;
		static const float	str_dmg_factor;
		static const float	dex_dmg_factor;
		static const float	dex_speed_factor;
		static const float	spirit_hpReg_factor;
};

#endif	/* PLAYER_H */

