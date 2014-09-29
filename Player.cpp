
#include <iostream>
#include "Player.hpp"

Player::Player() {
    SpritePlayer = NULL;
    player.width = 30;
    player.height = 30;
    player_atk_box.atkXpos = 0;
    player_atk_box.atkYpos = 0;
    player_atk_box.width = 30;
    player_atk_box.height = 15;
    str = 5;
    vita = 10;
    dex = 5;
    spirit = 10;
    level = 1;
    exp = 0;
    hp = calcHP();
    dmg = calcDMG();
    speed = calcSpeed();
    hpReg = calcHPreg();
    currentHP = hp;
    diagonal_moving = false;
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
    SpritePlayer->Load("data/player_sprite.bmp", 16, player.width, player.height); // not finished !
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
    xPos = 376.0;
    yPos = 520.0;

    animPhase = 0.0;
    temp_animPhase = 0.0;
    animTimer = 0.0;

    currentDirection = UP;

    attack_processed = false;
}

void Player::Render() {
    // set playerposition and render sprite
    SpritePlayer->SetPos(xPos, yPos);
    SpritePlayer->Render(animPhase);
}

void Player::Update() {
    ProcessMoving();
    AtkBoxPositioning();
    updateHitbox();
    Attacking();
    CheckPosition();
}

void Player::updateHitbox() {
    player.left = xPos;
    player.right = xPos + player.width;
    player.top = yPos;
    player.bottom = yPos + player.height;
}

void Player::AtkBoxPositioning() {
    int direction = getDirection();

    switch (direction) {
        case UP:
            player_atk_box.atkXpos = xPos;
            player_atk_box.atkYpos = yPos - player_atk_box.height;
            player_atk_box.top = player_atk_box.atkYpos;
            player_atk_box.bottom = (player_atk_box.atkYpos + player_atk_box.height);
            player_atk_box.right = (player_atk_box.atkXpos + player_atk_box.width);
            player_atk_box.left = player_atk_box.atkXpos;
            break;
        case DOWN:
            player_atk_box.atkXpos = xPos;
            player_atk_box.atkYpos = yPos + player.height;
            player_atk_box.top = player_atk_box.atkYpos;
            player_atk_box.bottom = (player_atk_box.atkYpos + player_atk_box.height);
            player_atk_box.right = (player_atk_box.atkXpos + player_atk_box.width);
            player_atk_box.left = player_atk_box.atkXpos;
            break;
        case LEFT:
            player_atk_box.atkXpos = xPos - player_atk_box.height;
            player_atk_box.atkYpos = yPos;
            player_atk_box.top = player_atk_box.atkYpos;
            player_atk_box.bottom = (player_atk_box.atkYpos + player_atk_box.width);
            player_atk_box.right = (player_atk_box.atkXpos + player_atk_box.height);
            player_atk_box.left = player_atk_box.atkXpos;
            break;
        case RIGHT:
            player_atk_box.atkXpos = xPos + player.width;
            player_atk_box.atkYpos = yPos;
            player_atk_box.top = player_atk_box.atkYpos;
            player_atk_box.bottom = (player_atk_box.atkYpos + player_atk_box.width);
            player_atk_box.right = (player_atk_box.atkXpos + player_atk_box.height);
            player_atk_box.left = player_atk_box.atkXpos;
            break;
        default: break;
    }
}

void Player::ProcessMoving() {
    // horizontal and vertical moving
    // -----------------------------------
    //
    if (g_pFramework->KeyDown(SDLK_LEFT)) {
        currentDirection = LEFT;

        // move player leftwards
        //
        if (!diagonal_moving)
            xPos -= (100.0 * speed) * g_pTimer->GetElapsed();

        // animate
        //
        animTimer += g_pTimer->GetElapsed();

        if (animTimer >= 0.2) {
            if (animPhase != 4 && animPhase != 5)
                animPhase = 4;
            else if (animPhase == 4)
                animPhase = 5;
            else if (animPhase == 5)
                animPhase = 4;
            animTimer = 0.0;
            temp_animPhase = animPhase;
        }
    } else if (g_pFramework->KeyDown(SDLK_RIGHT)) {
        currentDirection = RIGHT;

        // move player rightwards
        //
        if (!diagonal_moving)
            xPos += (100.0 * speed) * g_pTimer->GetElapsed();

        // animate
        //
        animTimer += g_pTimer->GetElapsed();

        if (animTimer >= 0.2) {
            if (animPhase != 8 && animPhase != 9)
                animPhase = 8;
            else if (animPhase == 8)
                animPhase = 9;
            else if (animPhase == 9)
                animPhase = 8;
            animTimer = 0.0;
            temp_animPhase = animPhase;
        }
    } else if (g_pFramework->KeyDown(SDLK_UP)) {
        currentDirection = UP;

        // move player up
        //
        if (!diagonal_moving)
            yPos -= (100.0 * speed) * g_pTimer->GetElapsed();

        // animate
        //
        animTimer += g_pTimer->GetElapsed();

        if (animTimer >= 0.2) {
            if (animPhase != 13 && animPhase != 14)
                animPhase = 13;
            else if (animPhase == 13)
                animPhase = 14;
            else if (animPhase == 14)
                animPhase = 13;
            animTimer = 0.0;
            temp_animPhase = animPhase;
        }
    } else if (g_pFramework->KeyDown(SDLK_DOWN)) {
        currentDirection = DOWN;

        // move player down
        //
        if (!diagonal_moving)
            yPos += (100.0 * speed) * g_pTimer->GetElapsed();

        // animate
        //
        animTimer += g_pTimer->GetElapsed();

        if (animTimer >= 0.2) {
            if (animPhase != 1)
                animPhase = 1;
            animTimer = 0.0;
            temp_animPhase = animPhase;
        }
    }

    // diagonal moving
    // ------------------
    //
    if (g_pFramework->KeyDown(SDLK_DOWN) && g_pFramework->KeyDown(SDLK_RIGHT)) {
        diagonal_moving = true;

        // move player down and right
        //
        xPos += (100.0 * speed) * g_pTimer->GetElapsed();
        yPos += (100.0 * speed) * g_pTimer->GetElapsed();
    } else if (g_pFramework->KeyDown(SDLK_DOWN) && g_pFramework->KeyDown(SDLK_LEFT)) {
        diagonal_moving = true;

        // move player down and left
        //
        xPos -= (100.0 * speed) * g_pTimer->GetElapsed();
        yPos += (100.0 * speed) * g_pTimer->GetElapsed();
    } else if (g_pFramework->KeyDown(SDLK_UP) && g_pFramework->KeyDown(SDLK_RIGHT)) {
        diagonal_moving = true;

        // move player up and right
        //
        xPos += (100.0 * speed) * g_pTimer->GetElapsed();
        yPos -= (100.0 * speed) * g_pTimer->GetElapsed();
    } else if (g_pFramework->KeyDown(SDLK_UP) && g_pFramework->KeyDown(SDLK_LEFT)) {
        diagonal_moving = true;

        // move player up and left
        //
        xPos -= (100.0 * speed) * g_pTimer->GetElapsed();
        yPos -= (100.0 * speed) * g_pTimer->GetElapsed();
    } else
        diagonal_moving = false;
}

void Player::Attacking() {
    if (g_pFramework->KeyDown(SDLK_SPACE) && attack_processed == false) {
        g_pCombat->PlayerAttack();

        if (currentDirection == UP)
            animPhase = 12;
        else if (currentDirection == DOWN)
            animPhase = 3;
        else if (currentDirection == LEFT)
            animPhase = 7;
        else if (currentDirection == RIGHT)
            animPhase = 11;

        attack_processed = true;
    }

    if (g_pFramework->KeyDown(SDLK_SPACE) == false) {
        animPhase = temp_animPhase;
        attack_processed = false;
    }
}

void Player::CheckPosition() {
    // not finished !
    //
    if (xPos < 0.0)
        xPos = 0.0;
    else if (xPos > 770.0)
        xPos = 770.0;
    else if (yPos < 0.0)
        yPos = 0.0;
    else if (yPos > 570.0)
        yPos = 570.0;

    /*		// not finished !
                    //
    if(animPhase < 0.0)
       animPhase = 0.0;
    else if(animPhase > 10.0)
       animPhase = 10.0;
     */
}

string Player::getName() {
    return name;
}

float Player::getHP() {
    return hp;
}

float Player::getDMG() {
    return dmg;
}

float Player::getSpeed() {
    return speed;
}

float Player::getHPreg() {
    return hpReg;
}

int Player::getStr() {
    return str;
}

int Player::getVita() {
    return vita;
}

int Player::getDex() {
    return dex;
}

int Player::getSpirit() {
    return spirit;
}

int Player::getLevel() {
    return level;
}

float Player::getCurrentHP() {
    return currentHP;
}

int Player::getDirection() {
    return currentDirection;
}

void Player::setName(string name) {
    this->name = name;
}

void Player::setHP(float hp) {
    this->hp = hp;
}

void Player::setDMG(float dmg) {
    this->dmg = dmg;
}

void Player::setSpeed(float speed) {
    this->speed = speed;
}

void Player::setHPreg(float hpReg) {
    this->hpReg = hpReg;
}

void Player::setStr(int str) {
    this->str = str;
}

void Player::setVita(int vita) {
    this->vita = vita;
}

void Player::setDex(int dex) {
    this->dex = dex;
}

void Player::setSpirit(int spirit) {
    this->spirit = spirit;
}

void Player::setLevel(int level) {
    this->level = level;
}

void Player::setCurrentHP(float newhp) {
    newhp = currentHP;
}

float Player::calcHP() {
    hp = vita_hp_factor * vita;
    return hp;
}

float Player::calcDMG() {
    dmg = (str_dmg_factor * str) + (dex_dmg_factor * dex);
    return dmg;
}

float Player::calcSpeed() {
    const int dex_points = 10;
    speed = dex_speed_factor * (dex / dex_points);

    if (speed < 1)
        speed = 1;

    return speed;
}

float Player::calcHPreg() {
    const int spirit_points = 10;
    hpReg = spirit_hpReg_factor * (spirit / spirit_points);
    return hpReg;
}

void Player::setEXP(long exp_gained) {
    exp = exp + exp_gained;
    bool level_up = false;

    do {
        int current_level = getLevel();
        long exp_needed = exp_base + ((current_level - 1) * exp_step);

        if (current_level < maxLevel && exp >= exp_needed) {
            exp = exp - exp_needed;
            levelUp();
            level_up = true;
        } else
            level_up = false;

    } while (level_up == true);
}

void Player::levelUp() {
    cout << "Level Up!" << endl;

    // increase level
    //
    int currentLevel = getLevel();
    currentLevel++;
    setLevel(currentLevel);

    cout << "You have reached level " << currentLevel << "!" << endl;

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
    cout << "Name:   " << name << endl;
    cout << "HP:     " << hp << endl;
    cout << "DMG:    " << dmg << endl;
    cout << "Speed:  " << speed << endl;
    cout << "HP-Reg: " << hpReg << endl;
    cout << "Str:    " << str << endl;
    cout << "Vita:   " << vita << endl;
    cout << "Dex:    " << dex << endl;
    cout << "Spirit: " << spirit << endl;
    cout << "Level:  " << level << endl;
    cout << "EXP:    " << exp << endl;
    cout << "---------------------" << endl;
}