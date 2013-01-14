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

			list<int>::iterator It1;
			for(It1 = Enemy_HitBox_Positions.begin(); It1 != Enemy_HitBox_Positions.end(); ++It1)
			{
				list<int>::iterator It2;
				for(It2 = Player_AtkBox_Positions.begin(); It2 != Player_AtkBox_Positions.end(); ++It2)
				{
					// cout << "Player_AtkBox_Pos: " << *It2 << "   ---   ";
					// cout << "Enemy_HitBox_Pos: " << *It1 << endl;

					if(*It1 == *It2)
						collision = true;
				}
			}
			
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