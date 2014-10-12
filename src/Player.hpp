
#include <string>
#include <list>
#include "Singleton.hpp"
#include "Sprite.hpp"
#include "Combat.hpp"

#ifndef PLAYER_H
#define	PLAYER_H

#define g_pPlayer Player::Get()

enum DIRECTIONS {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Player : public TSingleton<Player> {
public:
    Player();
    Player(const Player& orig);
    virtual ~Player();

    void Init();
    void Quit();
    void Reset();
    void Render();
    void Update();

    std::string getName();
    float getHP();
    float getDMG();
    float getSpeed();
    float getHPreg();
    int getStr();
    int getVita();
    int getDex();
    int getSpirit();
    int getLevel();
    float getCurrentHP();
    int getDirection();

    void setName(std::string p_name);
    void setHP(float p_hp);
    void setDMG(float p_dmg);
	void setSpeed ( float p_speed );
	void setHPreg ( float p_hpReg );
	void setStr ( int p_str );
	void setVita ( int p_vita );
	void setDex ( int p_dex );
	void setSpirit ( int p_spirit );
	void setLevel ( int p_level );
	void setCurrentHP ( float p_newhp );

	void setEXP ( long p_exp_gained );
    void levelUp();
    void chooseStatPoint();
    void displayStats();

    struct hitbox {
        int width;
        int height;
        int left;
        int right;
        int top;
        int bottom;
	} m_player;

    struct attackbox {
        float atkXpos;
        float atkYpos;
        int width;
        int height;
        int left;
        int right;
        int top;
        int bottom;
	} m_player_atk_box;

private:
    void ProcessMoving();
    void Attacking();
    void CheckPosition();
    void AtkBoxPositioning();
    void updateHitbox();

    float calcHP();
    float calcDMG();
    float calcSpeed();
    float calcHPreg();

    bool m_attack_processed;
	float m_xPos;
	float m_yPos;
	float m_animPhase;
	float m_temp_animPhase;
	float m_animTimer;
	float m_currentHP;
	float m_hp;
	float m_dmg;
	float m_speed;
	float m_hpReg;
	int m_str;
	int m_vita;
	int m_dex;
	int m_spirit;
	int m_level;
	long m_exp;
	int m_currentDirection;
	bool m_diagonal_moving;

	std::string m_name;
    CSprite *SpritePlayer;

	static const int maxLevel;
	static const long exp_base;
    static const long exp_step;
    static const float vita_hp_factor;
    static const float str_dmg_factor;
    static const float dex_dmg_factor;
    static const float dex_speed_factor;
    static const float spirit_hpReg_factor;
};

#endif	/* PLAYER_H */

