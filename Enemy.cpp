/* 
 * File:   Enemy.cpp
 * Author: Adrian
 * 
 * Created on 23. Dezember 2012, 18:30
 */

#include "Enemy.hpp"

Enemy::Enemy() 
{
	enemy.width = 30;
	enemy.height = 30;
	isHit = false;
	alive = true;
	currentHP = hp;
}

Enemy::Enemy(const Enemy& orig) 
{
}

Enemy::~Enemy() 
{
}

const float	Enemy::hp					= 150;
const long  Enemy::exp_earn				= 20000;

void Enemy::Init()
{
	SpriteEnemy = new CSprite;
	SpriteEnemy->Load("Data/Placeholder_Enemy.bmp", 1, enemy.width, enemy.height);    // not finished !
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
	updateHitbox();
	// AtkBoxPositioning();
}

// insert AtkBoxPositioning() here

void Enemy::updateHitbox()
{
	enemy.left		= xPos;
	enemy.right		= xPos + enemy.width;
	enemy.top		= yPos;
	enemy.bottom	= yPos + enemy.height;
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

bool Enemy::getHit()
{
	return isHit;
}

long Enemy::getEXP()
{
	return exp_earn;
}

void Enemy::setCurrentHP(float newhp)
{
	currentHP = newhp;
}

void Enemy::setHit(bool hit)
{
	isHit = hit;
}

void Enemy::kill()
{
	alive = false;
}

bool Enemy::isAlive()
{
	return alive;
}