/* 
 * File:   Enemy.cpp
 * Author: Adrian
 * 
 * Created on 23. Dezember 2012, 18:30
 */

#include "Enemy.hpp"

Enemy::Enemy() 
{
	currentHP = hp;
}

Enemy::Enemy(const Enemy& orig) 
{
}

Enemy::~Enemy() 
{
}

const float	Enemy::hp					= 150;
const long  Enemy::exp_earn				= 5000;

void Enemy::Init()
{
	SpriteEnemy = new CSprite;
	SpriteEnemy->Load("Data/Placeholder_Enemy.bmp", 1, 30, 30);    // not finished !
	SpriteEnemy->SetColorKey(255, 0, 255);
}

void Enemy::Quit()
{
	if(SpriteEnemy != NULL)
	{
		delete(SpriteEnemy);
		SpriteEnemy = NULL;
	}
}

void Enemy::Reset()
{
	// not finished
	//

	// startposition
	xPos = rand() % 770;
	yPos = rand() % 570;

	animPhase = 0.0;     // not finished !
}

void Enemy::Render()
{
	// set position and render sprite
	SpriteEnemy->SetPos(xPos, yPos);
	SpriteEnemy->Render(animPhase);
}

void Enemy::Update()
{
	KI();
}

void Enemy::KI()
{
	// insert KI-logic here and handle ProcessMoving() and CheckPosition()
}

void Enemy::ProcessMoving()
{
}

void Enemy::CheckPosition()
{
}

float Enemy::getHP()
{
    return hp;
}

float Enemy::getCurrentHP()
{
	return currentHP;
}

void Enemy::setCurrentHP(float newhp)
{
	newhp = currentHP;
}

