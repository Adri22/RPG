#ifndef COMBAT_HPP
#define COMBAT_HPP

#include <iostream>
#include <list>
#include "Singleton.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Game.hpp"

using namespace std;

#define g_pCombat Combat::Get()

enum WHOISATTACKING
{
    PLAYER,
    ENEMY
};

class Combat : public TSingleton<Combat>
{
	public:
		Combat();
		virtual ~Combat();

		void		PlayerAttack		();
		void		EnemyAttack			();

	private:
		void			CheckCollisions	(int whoisattacking);

		bool			collision;
		list<Enemy*>	eList;
		list<int>		Player_HitBox_Positions;
		list<int>		Player_AtkBox_Positions;
		list<int>		Enemy_HitBox_Positions;
		// list<int>		Enemy_AtkBox_Positions;
};

#endif