
#include <list>
#include "Singleton.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

#ifndef GAME_H
#define	GAME_H

#define g_pGame Game::Get()

class Game : public TSingleton<Game> {
public:
    Game();
    Game(const Game& orig);
    virtual ~Game();

    void Init();
    void Run();
    void Quit();

    void setEnemyList(list<Enemy*> eList);
    list<Enemy*> getEnemyList();

private:
    void getFPS();
    void ProcessEvents();
    void SpawnEnemys();
    void HandleEnemys();

    CSprite *SpriteBackground;
    bool gameRun; // Is the game still running?
    int frameCount;
    float frameTimer;
    float spawnTimer;
    list<Enemy*> EnemyList; // A list, full of enemys
};

#endif	/* GAME_H */

