#include "warrior.h"

class Plansza;
Warrior::Warrior(Plansza* p)
    :Player(p)
{
    heal=false;
    dodge=false;
    koniec=false;
    critical=20;
    hp=10;
    attack=30;
    defence=5;
}
