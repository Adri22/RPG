/* 
 * File:   Player.cpp
 * Author: Adrian
 * 
 * Created on 15. Dezember 2012, 17:47
 */

#include <iostream>
#include "Player.hpp"

Player::Player() 
{
	str = 5;
	vita = 10;
	dex = 5;
	spirit = 10;
	level = 1;
	hp = calcHP();
	dmg = calcDMG();
	speed = calcSpeed();
	hpReg = calcHPreg();
}

Player::Player(const Player& orig) 
{
}

Player::~Player() 
{
}

const float Player::vita_hp_factor			= 2.0;
const float Player::str_dmg_factor			= 2.0;
const float Player::dex_dmg_factor			= 1.5;
const float Player::dex_speed_factor		= 0.2;
const float Player::spirit_hpReg_factor		= 0.3;

string Player::getName()
{
    return name;
}

float Player::getHP()
{
    return hp;
}

float Player::getDMG()
{
	return dmg;
}

float Player::getSpeed()
{
	return speed;
}

float Player::getHPreg()
{
	return hpReg;
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

int Player::getLevel()
{
	return level;
}

void Player::setName(string name)
{
    this->name = name;
}

void Player::setHP(float hp)
{
    this->hp = hp;
}

void Player::setDMG(float dmg)
{
	this->dmg = dmg;
}

void Player::setSpeed(float speed)
{
	this->speed = speed;
}

void Player::setHPreg(float hpReg)
{
	this->hpReg = hpReg;
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

void Player::setLevel(int level)
{
	this->level = level;
}

float Player::calcHP()
{
	hp = vita_hp_factor * vita;
	return hp;
}

float Player::calcDMG()
{
	dmg = str_dmg_factor * str;
	dmg = dex_dmg_factor * dex;
	return dmg;
}

float Player::calcSpeed()
{
	const int dex_points = 15;
	speed = dex_speed_factor * (dex / dex_points);
	return speed;
}

float Player::calcHPreg()
{
	const int spirit_points = 10;
	hpReg = spirit_hpReg_factor * (spirit / spirit_points);
	return hpReg;
}

void Player::levelUp()
{
	// increase level
	//
	int currentLevel = getLevel();
	currentLevel++;
	setLevel(currentLevel);

	//	increase vita by 1 and calc new hp-value
	//
	int newVitaPoint = 1 + getVita();
	setVita(newVitaPoint);
	
	chooseStatPoint();

	calcHP();
	calcDMG();
	calcSpeed();
}

void Player::chooseStatPoint()
{
	// insert "choose-stat-logic" here and calc new dmg-value
	//

	// TEST
	int currentStr = getStr();
	currentStr++;
	setStr(currentStr);
	
	// TEST
	int currentDex = getDex();
	currentDex++;
	setDex(currentDex);
}

void Player::displayStats()
{
	cout << "---------------------" << endl;
	cout << "Name:   " <<	name		<< endl;
	cout << "HP:     " <<	hp			<< endl;
	cout << "DMG:    " <<	dmg			<< endl;
	cout << "Speed:  " <<	speed		<< endl;
	cout << "HP-Reg: " <<	hpReg		<< endl;
	cout << "Str:    " <<	str			<< endl;
	cout << "Vita:   " <<	vita		<< endl;
	cout << "Dex:    " <<	dex			<< endl;
	cout << "Spirit: " <<	spirit		<< endl;
	cout << "Level:  " <<	level		<< endl;
	cout << "---------------------" << endl;
}