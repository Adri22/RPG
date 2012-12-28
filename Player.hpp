/* 
 * File:   Player.h
 * Author: Adrian
 *
 * Created on 15. Dezember 2012, 17:47
 */

#include <string>
#include "Singleton.hpp"

#ifndef PLAYER_H
#define	PLAYER_H

#define g_pPlayer Player::Get()              // Makro zur einfacheren Verwendung

using namespace std;

class Player : public TSingleton<Player>
{
    public:
        Player();
        Player(const Player& orig);
        virtual ~Player();
        
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
        
		void setEXP(long exp_gained);
		void levelUp();
		void displayStats();
		void chooseStatPoint();

    private:
		float				calcHP();
		float				calcDMG();
		float				calcSpeed();
		float				calcHPreg();
        string				name;
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
		static const long	exp_base;
		static const long	exp_step;
		static const float	vita_hp_factor;
		static const float	str_dmg_factor;
		static const float	dex_dmg_factor;
		static const float	dex_speed_factor;
		static const float	spirit_hpReg_factor;
};

#endif	/* PLAYER_H */

