#ifndef MONSTER_H
#define MONSTER_H
#include <string>
#include "player.h"

struct m
{
    std::string name;
    int hp,attack,defence;
};

class Monster
{
private:
    static int los;
    int hp, attack, defence;
    std::string name;
    static int Num_monst;
    static m monsters[1000000];

public:
    friend void main_init(std::string);
    void showstats(int); //pokazuje statystyki potwora
    void boss(int); //tworzy bossa
    std::string getName();
    int getHp();
    int getAtt();
    int getDef();
    void test();
    Monster();
};

#endif
