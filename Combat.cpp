#include "Combat.hpp"


Combat::Combat()
{
	collision = false;
}

Combat::~Combat() {}

void Combat::PlayerAttack()
{
	// not finished
	//

	CheckCollisions(PLAYER);

	int enemies = 0;
	list<Enemy*>::iterator It;
	eList = g_pGame->getEnemyList();
	
	for(It = eList.begin(); It != eList.end(); ++It)
	{
		// test
		// just trying to remove hp from all enemies by attacking
		//
		float hp = (*It)->getCurrentHP();
		hp = hp - 51; // test-value --> 3 attacks should kill all enemies :D
		(*It)->setCurrentHP(hp);
		enemies++;

		if((*It)->getHit())
		{
			// enemy should damaged here
			//
			cout << "enemy hit" << endl;
			(*It)->setHit(false);
		}

		// cout << "Enemies: " << enemies << endl;
		// cout << "current HP: " << (*It)->getCurrentHP() << endl;
	}

	// return the list to original enemy-list
	//
	// g_pGame->setEnemyList(eList);
}

void Combat::EnemyAttack()
{
}

void Combat::CheckCollisions(int whoisattacking)
{
	collision = false;

	// use hit- and attackboxes here to calc pixels which are same "hit" by attack and position of target
	
	list<Enemy*>::iterator It;
	eList = g_pGame->getEnemyList();

	// player is attacking
	//
	if(whoisattacking == PLAYER)
	{
		cout << "player attacks" << endl;
		for(It = eList.begin(); It != eList.end(); ++It)
		{
			Enemy_HitBox_Positions = (*It)->getHitboxPositions();
			Player_AtkBox_Positions = g_pPlayer->getAtkboxPositions();

			// insert reworked collision-algorithm here

			if(collision)
			{
				(*It)->setHit(true);
				collision = false;
			}
		}
	}

	// enemy is attacking
	//
	if(whoisattacking == ENEMY)
	{
		// insert collision-checking by enemy-attacking here
	}
}