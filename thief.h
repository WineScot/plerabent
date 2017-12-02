#ifndef THIEF_H
#define THIEF_H

#include "player.h"


class Thief : public Player
{
    private:
        int dodge; //umiejetnosc do omijania pulapek, nie wiem jak ma dzialac, poniewaz nie mamy pulapek ;)
    public:
        Thief(Plansza*);
};

#endif // THIEF_H
