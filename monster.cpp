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

void Monster::showstats(int hpbattle)
{
    std::cout<<"Statystyki przeciwnika:"<<std::endl;
    std::cout<<"Nazwa: "<<name<<std::endl;
    std::cout<<"Punkty życia: "<<hpbattle<<std::endl;
    std::cout<<"Atak: "<<attack<<std::endl;
    std::cout<<"Obrona: "<<defence<<std::endl<<std::endl;
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

void Monster::boss(int player_points)
{
    hp=100-player_points;
    attack=100-player_points;
    defence=100-player_points;
    name="Sir Kamiński";
}
