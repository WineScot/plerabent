#ifndef WARRIOR_H
#define WARRIOR_H

#include "player.h"


class Warrior : public Player
{
private:
    int critical;//szansa na trafienie krytyczne
public:
    Warrior(Plansza *);
};

#endif // WARRIOR_H
