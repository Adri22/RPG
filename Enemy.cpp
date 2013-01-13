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

	currentHP = hp;

	animPhase = 0.0;     // not finished !
}

void Enemy::Render()
{
	// set position and render sprite
	SpriteEnemy->SetPos(xPos, yPos);
	SpriteEnemy->Render(animPhase);
}

list<float> Enemy::getHitboxPositions()
{
	hitboxPositions.clear();

	for(int x = 0; x <= enemy.width; x++)
		for(int y = 0; y <= enemy.height; y++)
		{
			hitboxPositions.push_back(xPos + x);
			hitboxPositions.push_back(yPos + y);
		}

	return hitboxPositions;
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

bool Enemy::getHit()
{
	return isHit;
}

void Enemy::setCurrentHP(float newhp)
{
	newhp = currentHP;
}

void Enemy::setHit(bool hit)
{
	isHit = hit;
}
