/* 
 * File:   Player.cpp
 * Author: Adrian
 * 
 * Created on 15. Dezember 2012, 17:47
 */

#include "Player.h"

Player::Player() 
{
}

Player::Player(const Player& orig) 
{
}

Player::~Player() 
{
}

string Player::getName()
{
    return name;
}

int Player::getHP()
{
    return hp;
}

int Player::getStr()
{
    return str;
}

int Player::getVita()
{
    return vita;
}

int Player::getDex()
{
    return dex;
}

int Player::getSpirit()
{
    return spirit;
}

void Player::setName(string name)
{
    this->name = name;
}

void Player::setHP(int hp)
{
    this->hp = hp;
}

void Player::setStr(int str)
{
    this->str = str;
}

void Player::setVita(int vita)
{
    this->vita = vita;
}

void Player::setDex(int dex)
{
    this->dex = dex;
}

void Player::setSpirit(int spirit)
{
    this->spirit = spirit;
}

