/* 
 * File:   Mage.h
 * Author: Adrian
 *
 * Created on 14. Dezember 2012, 00:31
 */

#include "Player.hpp"

#ifndef MAGE_H
#define	MAGE_H

class Mage : public Player
{
    public:
        Mage();
        Mage(const Mage& orig);
        virtual ~Mage();
        
        int getMana();
        
        void setMana(int mana);
        
    private:
        int             mana;

};

#endif	/* MAGE_H */

