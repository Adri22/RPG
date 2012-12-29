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
	SpritePlayer = NULL;
	str = 5;
	vita = 10;
	dex = 5;
	spirit = 10;
	level = 1;
	exp = 0;
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

const int	Player::maxLevel				= 99;
const long  Player::exp_base				= 50000;
const long  Player::exp_step				= 10000;
const float Player::vita_hp_factor			= 2.0;
const float Player::str_dmg_factor			= 2.0;
const float Player::dex_dmg_factor			= 1.5;
const float Player::dex_speed_factor		= 0.2;
const float Player::spirit_hpReg_factor		= 0.3;

void Player::Init()
{
	SpritePlayer = new CSprite;
	SpritePlayer->Load ("Data/Test.jpg", 11, 64, 64);
	// SpritePlayer->SetColorKey (255, 0, 255);
}

void Player::Quit()
{
	if(SpritePlayer != NULL)
	{
		delete(SpritePlayer);
		SpritePlayer = NULL;
	}
}

void Player::Reset()
{
	// Startposition des Spielers
	xPos = 376.0;
	xPos = 520.0;

	// Animationsphase
	animPhase = 1.0;
}

void Player::Render()
{
	// Position des Spielers setzen und Sprite rendern
	SpritePlayer->SetPos(xPos, yPos);
	SpritePlayer->Render(animPhase);
}

void Player::Update()
{
	ProcessMoving();
	CheckPosition();
}

void Player::ProcessMoving()
{
	if(g_pFramework->KeyDown(SDLK_LEFT))
	{
		// Spieler nach links bewegen
		xPos -= 300.0 * g_pTimer->GetElapsed();

		// Animieren
		// animPhase -= 20.0f * g_pTimer->GetElapsed();
	}
	else if(g_pFramework->KeyDown(SDLK_RIGHT))
	{
		// Spieler nach rechts bewegen
		xPos += 300.0 * g_pTimer->GetElapsed();

		// Animieren
		// animPhase += 20.0f * g_pTimer->GetElapsed();
	}
}

void Player::CheckPosition()
{
	if(xPos < 0.0)
	   xPos = 0.0;
	else if(xPos > 752.0)
	   xPos = 752.0;
/*
	if(animPhase < 0.0)
	   animPhase = 0.0;
	else if(animPhase > 10.0)
	   animPhase = 10.0;
*/
}

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

void Player::setEXP(long exp_gained)
{
	exp = exp + exp_gained;
	bool level_up = false;

	do
	{
		int current_level = getLevel();
		long exp_needed = exp_base + ((current_level - 1) * exp_step);
		
		if(current_level < maxLevel && exp >= exp_needed)
		{
			exp = exp - exp_needed;
			levelUp();
			level_up = true;
		}
		else
			level_up = false;

	}while(level_up == true);
}

void Player::levelUp()
{
	cout << "Level Up!" << endl;

	// increase level
	//
	int currentLevel = getLevel();
	currentLevel++;
	setLevel(currentLevel);

	cout << "You have reached level " << currentLevel << "!" << endl;

	//	increase vita by 1 and calc new hp-value
	//	everytime, the player levels up, vita gets increased
	int newVitaPoint = 1 + getVita();
	setVita(newVitaPoint);
	
	chooseStatPoint();

	calcHP();
	calcDMG();
	calcSpeed();
	calcHPreg();
}

void Player::chooseStatPoint()
{
	cout << "Increase your stats!" << endl;
	cout << "You can choose between three attributes: " << endl;
	cout << "Strength	[1]" << endl;
	cout << "Dexterity	[2]" << endl;
	cout << "Spirit		[3]" << endl;
	
	bool pointSet;
	int choose;
	int currentStr = getStr();
	int currentDex = getDex();
	int currentSpirit = getSpirit();

	do
	{
		cout << "Enter: ";
		cin >> choose;

		switch(choose)
		{
			case 1:
				currentStr++;
				setStr(currentStr);
				pointSet = true;
				break;

			case 2:
				currentDex++;
				setDex(currentDex);
				pointSet = true;
				break;

			case 3:
				currentSpirit++;
				setSpirit(currentSpirit);
				pointSet = true;
				break;

			default:
				cout << "wrong entry!" << endl;
				pointSet = false;
				break;
		}
	}while(!pointSet);
}

void Player::displayStats()
{
	cout << "---------------------"		<< endl;
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
	cout << "EXP:    " <<	exp			<< endl;
	cout << "---------------------"		<< endl;
}