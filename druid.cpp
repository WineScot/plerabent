#include "druid.h"


Druid::Druid(Plansza* p)
    :Player(p)
{
    heal=true;
    dodge=false;
    koniec=false;
    critical=0;
    hp=20;
    attack=10;
    defence=10;
}
