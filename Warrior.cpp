/* 
 * File:   Warrior.cpp
 * Author: Adrian
 * 
 * Created on 14. Dezember 2012, 00:28
 */

#include "Warrior.hpp"

Warrior::Warrior() 
{
}

Warrior::Warrior(const Warrior& orig) 
{
}

Warrior::~Warrior() 
{
}

int Warrior::getRage()
{
    return rage;
}

void Warrior::setRage(int rage)
{
    this->rage = rage;
}