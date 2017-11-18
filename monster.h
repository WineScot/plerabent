#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <fstream>

using namespace std;

class Monster
{
    int hp, attack, defence;
    string name;
public:
    Monster();
    //virtual ~Monster();
    friend void init();
};

#endif // MONSTER_H
