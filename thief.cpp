#include "thief.h"

Thief::Thief(Plansza* p)
    :Player(p)
{
    heal=false;
    dodge=true;
    koniec=false;
    critical=0;
    hp=15;
    attack=10;
    defence=15;
}
