/* 
 * File:   Game.cpp
 * Author: Adrian
 * 
 * Created on 23. Dezember 2012, 18:38
 */

#include "Game.hpp"

Game::Game() 
{
	SpriteBackground = NULL;
}

Game::Game(const Game& orig) 
{
}

Game::~Game() 
{
}

void Game::Init()
{
	// initialize new player
	g_pPlayer->Init();
	g_pPlayer->Reset();

	SpriteBackground = new CSprite;
	SpriteBackground->Load("data/Background_Test.bmp");

	spawnTimer = 0.0;
	frameTimer = 0.0;
	frameCount = 0;

	// game starts
	gameRun = true;
}

void Game::Run()
{
	// Main-Loop
	//
	while(gameRun == true)
	{
		ProcessEvents ();

		// update framework and delete buffer
		g_pFramework->Update();
		g_pFramework->Clear();

		SpriteBackground->Render();

		// update and render player
		g_pPlayer->Update();
		g_pPlayer->Render();

		SpawnEnemys();
		HandleEnemys();

		g_pFramework->Flip();
	}
}

void Game::Quit()
{
	g_pPlayer->Del();

	if(SpriteBackground != NULL)
	{
		delete(SpriteBackground);
		SpriteBackground = NULL;
	}

	list<Enemy*>::iterator It;
	for(It = EnemyList.begin(); It != EnemyList.end(); ++It)
		delete (*It);
}

void Game::getFPS()
{
	frameCount++;
	frameTimer += g_pTimer->GetElapsed();

	if(frameTimer >= 1)
	{
		cout << "fps: " << frameCount << endl;
		frameTimer = 0.0;
		frameCount = 0;
	}
}

void Game::ProcessEvents()
{
	SDL_Event Event;

	if(SDL_PollEvent(&Event))
	{
		switch(Event.type)
		{
			case SDL_QUIT:
				gameRun = false;
				break;

			case SDL_KEYDOWN:
				switch(Event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						gameRun = false;
						break;
				}
				break;
		}
	}
}

void Game::SpawnEnemys()
{
	spawnTimer += g_pTimer->GetElapsed();

	if(spawnTimer >= 10)
	{
		Enemy* enemy = new Enemy();
		enemy->Init();
		enemy->Reset();

		EnemyList.push_back(enemy);

		spawnTimer = 0.0;
	}
}

void Game::HandleEnemys()
{
	list<Enemy*>::iterator It;

	for(It = EnemyList.begin(); It != EnemyList.end(); ++It)
	{
		(*It)->Render();
		(*It)->Update();

		if((*It)->getCurrentHP() <= 0 && (*It)->isAlive())
		{
			(*It)->kill();
			g_pPlayer->setEXP((*It)->getEXP());
			delete (*It);
			EnemyList.erase(It);
			break;
		}
	}
}

list<Enemy*> Game::getEnemyList()
{
	return EnemyList;
}

void Game::setEnemyList(list<Enemy*> eList)
{
	EnemyList = eList;
}


