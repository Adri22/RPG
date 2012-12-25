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
        
        string getName();
        int getHP();
        int getStr();
        int getVita();
        int getDex();
        int getSpirit();
        
        void setName(string name);
        void setHP(int hp);
        void setStr(int str);
        void setVita(int vita);
        void setDex(int dex);
        void setSpirit(int spirit);
        
    private:
        string          name;
        int             hp;
        int             str;
        int             vita;
        int             dex;
        int             spirit;
};

#endif	/* PLAYER_H */

