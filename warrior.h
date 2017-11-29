#ifndef WARRIOR_H
#define WARRIOR_H

#include <Player.h>


class Warrior : public Player
{
    Warrior(Plansza* p);
private:
    int critical;//szansa na trafienie krytyczne
};

#endif // WARRIOR_H
