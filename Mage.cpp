/* 
 * File:   Mage.cpp
 * Author: Adrian
 * 
 * Created on 14. Dezember 2012, 00:31
 */

#include "Mage.h"

Mage::Mage() 
{
}

Mage::Mage(const Mage& orig) 
{
}

Mage::~Mage() 
{
}

int Mage::getMana()
{
    return mana;
}

void Mage::setMana(int mana)
{
    this->mana = mana;
}