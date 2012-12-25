/* 
 * File:   Enemy.h
 * Author: Adrian
 *
 * Created on 23. Dezember 2012, 18:30
 */

#include <string>

#ifndef ENEMY_H
#define	ENEMY_H

class Enemy 
{
    public:
        Enemy();
        Enemy(const Enemy& orig);
        virtual ~Enemy();
        
        int getHP();
        
        void setHP(int hp);

    private:
        int             hp;

};

#endif	/* ENEMY_H */

