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
    void Bardzo_Fajna_Funkcja_Do_Sprytnego_Balansowania_Atrybuow_Potwora_Aby_Rozgrywka_Byla_Wyrownana(int);
    std::string getName();
    int getHp();
    int getAtt();
    int getDef();
    void test();
    Monster();
};

#endif
