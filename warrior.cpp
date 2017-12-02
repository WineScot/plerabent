#include "warrior.h"

class Plansza;
Warrior::Warrior(Plansza* p)
    :Player(p)
{
    hp=10;
    attack=30;
    defence=5;
}
