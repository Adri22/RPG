#include "Combat.hpp"


Combat::Combat()
{
	collision = false;
}

Combat::~Combat() {}

void Combat::PlayerAttack()
{
	CheckCollisions(PLAYER);

	list<Enemy*>::iterator It;
	eList = g_pGame->getEnemyList();
	
	for(It = eList.begin(); It != eList.end(); ++It)
	{
		if((*It)->getHit())
		{
			float hp = (*It)->getCurrentHP();
			hp-=g_pPlayer->getDMG();
			(*It)->setCurrentHP(hp);
			(*It)->setHit(false);
		}

		cout << "Enemy-HP: " << (*It)->getCurrentHP() << endl;
	}

	// return the list to original enemy-list
	//
	g_pGame->setEnemyList(eList);
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
			// (*It)->getHitbox();
			// g_pPlayer->getAtkbox();

			// insert reworked collision-algorithm here

			// test
			collision = true;

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