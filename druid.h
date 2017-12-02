#ifndef DRUID_H
#define DRUID_H

#include "player.h"

class Druid : public Player
{
    private:
        int heal; //umiejetnosc druida do leczenia po walce
    public:
        Druid(Plansza *);

};

#endif // DRUID_H
