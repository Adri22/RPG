
#include <iostream>
#include "Player.hpp"

Player::Player() {
    SpritePlayer = NULL;
	m_player.width = 30;
	m_player.height = 30;
	m_m_player_atk_box.atkXpos = 0;
	m_m_player_atk_box.atkYpos = 0;
	m_m_player_atk_box.width = 30;
	m_m_player_atk_box.height = 15;
    m_str = 5;
	m_vita = 10;
	m_dex = 5;
	m_spirit = 10;
	m_level = 1;
	m_exp = 0;
	m_hp = calcHP ( );
	m_dmg = calcDMG ( );
	m_speed = calcSpeed ( );
	m_hpReg = calcHPreg ( );
	m_currentHP = hp;
	m_diagonal_moving = false;
}

Player::Player(const Player& orig) {
}

Player::~Player() {
}

const int Player::maxLevel = 99;
const long Player::exp_base = 50000;
const long Player::exp_step = 10000;
const float Player::vita_hp_factor = 2.5;
const float Player::str_dmg_factor = 2.0;
const float Player::dex_dmg_factor = 1.5;
const float Player::dex_speed_factor = 1.2;
const float Player::spirit_hpReg_factor = 0.3;

void Player::Init() {
    SpritePlayer = new CSprite;
	SpritePlayer->Load ( "data/player_sprite.bmp", 16, m_player.width, m_player.height ); // not finished !
    SpritePlayer->SetColorKey(255, 0, 255);
}

void Player::Quit() {
    if (SpritePlayer != NULL) {
        delete(SpritePlayer);
        SpritePlayer = NULL;
    }
}

void Player::Reset() {
    // startposition
	m_xPos = 376.0;
	m_yPos = 520.0;

	m_animPhase = 0.0;
	m_temp_animPhase = 0.0;
	m_animTimer = 0.0;

	m_currentDirection = UP;

	m_attack_processed = false;
}

void Player::Render() {
    // set playerposition and render sprite
	SpritePlayer->SetPos ( m_xPos, m_yPos );
	SpritePlayer->Render ( m_animPhase );
}

void Player::Update() {
    ProcessMoving();
    AtkBoxPositioning();
    updateHitbox();
    Attacking();
    CheckPosition();
}

void Player::updateHitbox() {
	m_player.left = m_xPos;
	m_player.right = m_xPos + m_player.width;
	m_player.top = m_yPos;
	m_player.bottom = m_yPos + m_player.height;
}

void Player::AtkBoxPositioning() {
    int l_direction = getDirection();

    switch (l_direction) {
        case UP:
            m_player_atk_box.atkXpos = m_xPos;
			m_player_atk_box.atkYpos = m_yPos - m_player_atk_box.height;
            m_player_atk_box.top = m_player_atk_box.atkYpos;
            m_player_atk_box.bottom = (m_player_atk_box.atkYpos + m_player_atk_box.height);
            m_player_atk_box.right = (m_player_atk_box.atkXpos + m_player_atk_box.width);
            m_player_atk_box.left = m_player_atk_box.atkXpos;
            break;
        case DOWN:
			m_player_atk_box.atkXpos = m_xPos;
			m_player_atk_box.atkYpos = m_yPos + m_player.height;
            m_player_atk_box.top = m_player_atk_box.atkYpos;
            m_player_atk_box.bottom = (m_player_atk_box.atkYpos + m_player_atk_box.height);
            m_player_atk_box.right = (m_player_atk_box.atkXpos + m_player_atk_box.width);
            m_player_atk_box.left = m_player_atk_box.atkXpos;
            break;
        case LEFT:
			m_player_atk_box.atkXpos = m_xPos - m_player_atk_box.height;
			m_player_atk_box.atkYpos = m_yPos;
            m_player_atk_box.top = m_player_atk_box.atkYpos;
            m_player_atk_box.bottom = (m_player_atk_box.atkYpos + m_player_atk_box.width);
            m_player_atk_box.right = (m_player_atk_box.atkXpos + m_player_atk_box.height);
            m_player_atk_box.left = m_player_atk_box.atkXpos;
            break;
        case RIGHT:
			m_player_atk_box.atkXpos = m_xPos + m_player.width;
			m_player_atk_box.atkYpos = m_yPos;
            m_player_atk_box.top = m_player_atk_box.atkYpos;
            m_player_atk_box.bottom = (m_player_atk_box.atkYpos + m_player_atk_box.width);
            m_player_atk_box.right = (m_player_atk_box.atkXpos + m_player_atk_box.height);
            m_player_atk_box.left = m_player_atk_box.atkXpos;
            break;
        default: break;
    }
}

void Player::ProcessMoving() {
    // horizontal and vertical moving
    // -----------------------------------
    //
	if ( g_pFramework->KeyDown ( SDLK_LEFT ) ) {
		m_currentDirection = LEFT;

        // move player leftwards
        //
		if ( !m_diagonal_moving )
			m_xPos -= ( 100.0 * m_speed ) * g_pTimer->GetElapsed ( );

        // animate
        //
		m_animTimer += g_pTimer->GetElapsed ( );

        if (m_animTimer >= 0.2) {
			if ( m_animPhase != 4 && m_animPhase != 5 )
				m_animPhase = 4;
			else if ( m_animPhase == 4 )
				m_animPhase = 5;
			else if ( m_animPhase == 5 )
				m_animPhase = 4;
			m_animTimer = 0.0;
			m_temp_animPhase = m_animPhase;
        }
    } else if (g_pFramework->KeyDown(SDLK_RIGHT)) {
		m_currentDirection = RIGHT;

        // move player rightwards
        //
		if ( !m_diagonal_moving )
			m_xPos += ( 100.0 * m_speed ) * g_pTimer->GetElapsed ( );

        // animate
        //
		m_animTimer += g_pTimer->GetElapsed ( );

		if ( m_animTimer >= 0.2 ) {
			if ( m_animPhase != 8 && m_animPhase != 9 )
				m_animPhase = 8;
			else if ( m_animPhase == 8 )
				m_animPhase = 9;
			else if ( m_animPhase == 9 )
				m_animPhase = 8;
            m_animTimer = 0.0;
			m_temp_animPhase = m_animPhase;
        }
    } else if (g_pFramework->KeyDown(SDLK_UP)) {
        m_currentDirection = UP;

        // move player up
        //
        if (!m_diagonal_moving)
			m_yPos -= ( 100.0 * m_speed ) * g_pTimer->GetElapsed ( );

        // animate
        //
		m_animTimer += g_pTimer->GetElapsed ( );

		if ( m_animTimer >= 0.2 ) {
			if ( m_animPhase != 13 && m_animPhase != 14 )
				m_animPhase = 13;
			else if ( m_animPhase == 13 )
				m_animPhase = 14;
			else if ( m_animPhase == 14 )
				m_animPhase = 13;
			m_animTimer = 0.0;
			m_temp_animPhase = m_animPhase;
        }
    } else if (g_pFramework->KeyDown(SDLK_DOWN)) {
        m_currentDirection = DOWN;

        // move player down
        //
        if (!m_diagonal_moving)
            m_yPos += (100.0 * m_speed) * g_pTimer->GetElapsed();

        // animate
        //
        m_animTimer += g_pTimer->GetElapsed();

		if ( m_animTimer >= 0.2 ) {
            if (m_animPhase != 1)
				m_animPhase = 1;
			m_animTimer = 0.0;
			m_temp_animPhase = m_animPhase;
        }
    }

    // diagonal moving
    // ------------------
    //
    if (g_pFramework->KeyDown(SDLK_DOWN) && g_pFramework->KeyDown(SDLK_RIGHT)) {
        m_diagonal_moving = true;

        // move player down and right
        //
		m_xPos += ( 100.0 * m_speed ) * g_pTimer->GetElapsed ( );
		m_yPos += ( 100.0 * m_speed ) * g_pTimer->GetElapsed ( );
    } else if (g_pFramework->KeyDown(SDLK_DOWN) && g_pFramework->KeyDown(SDLK_LEFT)) {
		m_diagonal_moving = true;

        // move player down and left
        //
		m_xPos -= ( 100.0 * m_speed ) * g_pTimer->GetElapsed ( );
		m_yPos += ( 100.0 * m_speed ) * g_pTimer->GetElapsed ( );
    } else if (g_pFramework->KeyDown(SDLK_UP) && g_pFramework->KeyDown(SDLK_RIGHT)) {
		m_diagonal_moving = true;

        // move player up and right
        //
		m_xPos += ( 100.0 * m_speed ) * g_pTimer->GetElapsed ( );
		m_yPos -= ( 100.0 * m_speed ) * g_pTimer->GetElapsed ( );
    } else if (g_pFramework->KeyDown(SDLK_UP) && g_pFramework->KeyDown(SDLK_LEFT)) {
		m_diagonal_moving = true;

        // move player up and left
        //
		m_xPos -= ( 100.0 * m_speed ) * g_pTimer->GetElapsed ( );
		m_yPos -= ( 100.0 * m_speed ) * g_pTimer->GetElapsed ( );
    } else
		m_diagonal_moving = false;
}

void Player::Attacking() {
	if ( g_pFramework->KeyDown ( SDLK_SPACE ) && m_attack_processed == false ) {
        g_pCombat->PlayerAttack();

		if ( m_currentDirection == UP )
			m_animPhase = 12;
		else if ( m_currentDirection == DOWN )
			m_animPhase = 3;
		else if ( m_currentDirection == LEFT )
			m_animPhase = 7;
		else if ( m_currentDirection == RIGHT )
			m_animPhase = 11;

		m_attack_processed = true;
    }

    if (g_pFramework->KeyDown(SDLK_SPACE) == false) {
		m_animPhase = m_temp_animPhase;
		m_attack_processed = false;
    }
}

void Player::CheckPosition() {
    // not finished !
    //
	if ( m_xPos < 0.0 )
		m_xPos = 0.0;
	else if ( m_xPos > 770.0 )
		m_xPos = 770.0;
	else if ( m_yPos < 0.0 )
		m_yPos = 0.0;
    else if (yPos > 570.0)
		m_yPos = 570.0;

    /*		// not finished !
                    //
    if(animPhase < 0.0)
       animPhase = 0.0;
    else if(animPhase > 10.0)
       animPhase = 10.0;
     */
}

string Player::getName() {
	return m_name;
}

float Player::getHP() {
	return m_hp;
}

float Player::getDMG() {
	return m_dmg;
}

float Player::getSpeed() {
	return m_speed;
}

float Player::getHPreg() {
	return m_hpReg;
}

int Player::getStr() {
	return m_str;
}

int Player::getVita() {
	return m_vita;
}

int Player::getDex() {
	return m_dex;
}

int Player::getSpirit() {
	return m_spirit;
}

int Player::getLevel() {
	return m_level;
}

float Player::getCurrentHP() {
	return m_currentHP;
}

int Player::getDirection() {
	return m_currentDirection;
}

void Player::setName(string p_name) {
	m_name = p_name;
}

void Player::setHP(float p_hp) {
	m_hp = p_hp;
}

void Player::setDMG(float p_dmg) {
	m_dmg = p_dmg;
}

void Player::setSpeed ( float p_speed ) {
	m_speed = p_speed;
}

void Player::setHPreg ( float p_hpReg ) {
	m_hpReg = p_hpReg;
}

void Player::setStr ( int p_str ) {
	m_str = p_str;
}

void Player::setVita ( int p_vita ) {
	m_vita = p_vita;
}

void Player::setDex ( int p_dex ) {
	m_dex = p_dex;
}

void Player::setSpirit ( int p_spirit ) {
	m_spirit = p_spirit;
}

void Player::setLevel ( int p_level ) {
	m_level = p_level;
}

void Player::setCurrentHP ( float p_newhp ) {
	m_newhp = p_newhp;
}

float Player::calcHP() {
    m_hp = vita_hp_factor * m_vita;
	return m_hp;
}

float Player::calcDMG() {
	m_dmg = ( str_dmg_factor * m_str ) + ( dex_dmg_factor * m_dex );
	return m_dmg;
}

float Player::calcSpeed() {
    const int l_dex_points = 10;
	m_speed = dex_speed_factor * ( m_dex / l_dex_points );

	if ( m_speed < 1 )
		m_speed = 1;

	return m_speed;
}

float Player::calcHPreg() {
    const int l_spirit_points = 10;
	m_hpReg = spirit_hpReg_factor * ( m_spirit / l_spirit_points );
	return m_hpReg;
}

void Player::setEXP(long exp_gained) {
	m_exp += exp_gained;
    bool level_up = false;

    do {
        int current_level = getLevel();
        long exp_needed = exp_base + ((current_level - 1) * exp_step);

		if ( current_level < maxLevel && m_exp >= exp_needed ) {
			m_exp -= exp_needed;
            levelUp();
            level_up = true;
        } else
            level_up = false;

    } while (level_up == true);
}

void Player::levelUp() {
    std::cout << "Level Up!" << endl;

    // increase level
    //
    int currentLevel = getLevel();
    currentLevel++;
    setLevel(currentLevel);

    std::cout << "You have reached level " << currentLevel << "!" << std::endl;

    //	increase vita by 1 and calc new hp-value
    //	everytime, the player levels up, vita gets increased
    int newVitaPoint = 1 + getVita();
    setVita(newVitaPoint);

    chooseStatPoint();

    calcHP();
    calcDMG();
    calcSpeed();
    calcHPreg();
}

void Player::chooseStatPoint() {
    cout << "Increase your stats!" << endl;
    cout << "You can choose between three attributes: " << endl;
    cout << "Strength	[1]" << endl;
    cout << "Dexterity	[2]" << endl;
    cout << "Spirit		[3]" << endl;

    bool pointSet;
    int choose;
    int currentStr = getStr();
    int currentDex = getDex();
    int currentSpirit = getSpirit();

    do {
        cout << "Enter: ";
        cin >> choose;

        switch (choose) {
            case 1:
                currentStr++;
                setStr(currentStr);
                pointSet = true;
                break;

            case 2:
                currentDex++;
                setDex(currentDex);
                pointSet = true;
                break;

            case 3:
                currentSpirit++;
                setSpirit(currentSpirit);
                pointSet = true;
                break;

            default:
                cout << "wrong entry!" << endl;
                pointSet = false;
                break;
        }
    } while (!pointSet);
}

void Player::displayStats() {
    cout << "---------------------" << endl;
	cout << "Name:   " << m_name << endl;
	cout << "HP:     " << m_hp << endl;
	cout << "DMG:    " << m_dmg << endl;
	cout << "Speed:  " << m_speed << endl;
	cout << "HP-Reg: " << m_hpReg << endl;
	cout << "Str:    " << m_str << endl;
	cout << "Vita:   " << m_vita << endl;
	cout << "Dex:    " << m_dex << endl;
	cout << "Spirit: " << m_spirit << endl;
	cout << "Level:  " << m_level << endl;
	cout << "EXP:    " << m_exp << endl;
    cout << "---------------------" << endl;
}