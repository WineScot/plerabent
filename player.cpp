#include "player.h"
#include <cstdlib>
#include "monster.h"
#include "event.h"

Player::Player(int base_hp, int base_attack, int base_defence)
{
    base_hp=base_hp;
    hp=base_hp;
    base_attack=base_attack;
    attack=base_attack;
    base_defence=base_defence;
    defence=base_defence;
    position=1;
}

void Player::battle(Monster *e)
{
    int monsterHp = e->getHp();
    int monsterAtt = e->getAtt();
    int monsterDef = e->getDef();
    bool tour=rand()%2; //losowanie tury
    while(hp>0 && monsterHp>0)
    {
        int base=rand()%6+1; //rzut kostką
        if(tour)
        {
            base+=attack-monsterAtt;
            base=std::min(base,1);
            monsterHp-=base;
        }
        else
        {
            base+=monsterAtt-defence;
            base=std::min(base,1);
            hp-=base;
        }
        tour=!tour;
    }
}

void Player::c_event(Event *e)
{
    battle(e->getM()); //walka z potworem
    hp+=e->getHp();
    attack+=e->getAtt();
    defence+=e->getDef();
}

void Player::p_move()
{
    int mov=rand()%6+1;
    position+=mov; //tymczasowe
}
