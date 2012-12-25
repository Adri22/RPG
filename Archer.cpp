/* 
 * File:   Archer.cpp
 * Author: Adrian
 * 
 * Created on 14. Dezember 2012, 00:31
 */

#include "Archer.hpp"

Archer::Archer() 
{
}

Archer::Archer(const Archer& orig) 
{
}

Archer::~Archer() 
{
}

int Archer::getFocus()
{
    return focus;
}

void Archer::setFocus(int focus)
{
    this->focus = focus;
}