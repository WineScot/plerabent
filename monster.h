#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <fstream>


class Monster
{
    int hp, attack, defence;
    std::string name;
public:
    Monster();
    //virtual ~Monster();
    friend void init();
};

#endif // MONSTER_H
