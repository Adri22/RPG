
#include "Player.hpp"

#ifndef WARRIOR_H
#define	WARRIOR_H

class Warrior : public Player {
public:
    Warrior();
    Warrior(const Warrior& orig);
    virtual ~Warrior();

    int getRage();

    void setRage(int rage);

private:
    int rage;

};

#endif	/* WARRIOR_H */

