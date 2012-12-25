/* 
 * File:   Enemy.cpp
 * Author: Adrian
 * 
 * Created on 23. Dezember 2012, 18:30
 */

#include "Enemy.hpp"

Enemy::Enemy() 
{
}

Enemy::Enemy(const Enemy& orig) 
{
}

Enemy::~Enemy() 
{
}

int Enemy::getHP()
{
    return hp;
}

void Enemy::setHP(int hp)
{
    this->hp = hp;
}