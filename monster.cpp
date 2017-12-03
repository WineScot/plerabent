#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>

#include "monster.h"
#include "funkcje.h"

m Monster::monsters[];
int Monster::Num_monst;
int Monster::los;

void Monster::test()
{
    for(int i=1;i<=Num_monst;i++)
    {
        std::cout<<monsters[i].name.c_str()<<std::endl;
        std::cout<<monsters[i].hp<<std::endl;
        std::cout<<monsters[i].attack<<std::endl;
        std::cout<<monsters[i].defence<<std::endl;
    }
}

int Monster::getHp()
{
    return hp;
}

int Monster::getAtt()
{
    return attack;
}

int Monster::getDef()
{
    return defence;
}

std::string Monster::getName()
{
    return name;
}

void Monster::Bardzo_Fajna_Funkcja_Do_Sprytnego_Balansowania_Atrybuow_Potwora_Aby_Rozgrywka_Byla_Wyrownana(int pozycja_gracza)
{
    this->hp=hp*pozycja_gracza/15;
    this->attack=attack*pozycja_gracza/15;
    this->defence=defence*pozycja_gracza/15;
}

Monster::Monster()
{
    los++;
    srand(los);
    int x=(rand()%Num_monst)+1;
    name=monsters[x].name;
    hp=monsters[x].hp;
    attack=monsters[x].attack;
    defence=monsters[x].defence;
}
