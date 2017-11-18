#include "player.h"
#include <cstdlib>

using namespace std;

Player::player(int base_hp, int base_attack, int base_defence)
{
    this->base_hp=base_hp;
    hp=base_hp;
    this->base_attack=base_attack;
    attack=base_attack;
    this->base_defence=base_defence;
    defence=base_defence;
    position=1;
}

void Player::battle(Monster enemy)
{
    bool tour=rand()%2; //losowanie tury
    while(hp>0 && enemy.hp>0)
    {
        int base=rand()%6+1; //rzut kostk¹
        if(tour)
        {
            base+=attack-enemy.defence;
            base=min(base,1);
            enemy.hp-=base;
        }
        else
        {
            base+=enemy.attack-defence;
            base=min(base,1);
            hp-=base;
        }
        tour=!tour;
    }
}

void Player::c_event(Event e)
{
    battle(e.m); //walka z potworem
    hp+=e.hp;
    attack+=e.attack;
    defence+=e.defence;
}

void Player::p_move()
{
    int mov=rand()%6+1;
    position+=mov; //tymczasowe
}
