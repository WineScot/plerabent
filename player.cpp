#include "player.h"
#include <cstdlib>
#include "monster.h"
#include "event.h"
#include "plansza.h"
#include "funkcje.h"


Player::Player(Plansza* p)
{
    position=1;
    this->p=p;
}
void Player::battle(Event* eve)
{
    int monsterHp = eve->getM()->getHp();
    int monsterAtt = eve->getM()->getAtt();
    int monsterDef = eve->getM()->getDef();
    bool tour=rand()%2; //losowanie tury
    system(clear);
    if(tour) std::cout<<"Atakujesz jako pierwszy!"<<std::endl;
    else std::cout<<"Przeciwnik atakuje jako pierwszy!"<<std::endl;
    sleep(1000);
    while(hp>0 && monsterHp>0)
    {
        int base=rand()%6+1; //rzut kostką
        if(tour)
        {
            system(clear);
            std::cout<<"Twoja tura!"<<std::endl;
            sleep(500);
            WAIT;
            std::cout<<"Rzut kostka: "<<base<<std::endl;
            base+=attack-monsterDef;
            base=std::max(base,1);
            monsterHp-=base;
            sleep(500);
            std::cout<<"Zadales "<<base<<" obrazen"<<std::endl;
            sleep(1000);
        }
        else
        {
            system(clear);
            std::cout<<"Tura przeciwnika!"<<std::endl;
            sleep(500);
            std::cout<<"Rzut kostka: "<<base<<std::endl;
            base+=monsterAtt-defence;
            base=std::max(base,1);
            hp-=base;
            std::cout<<"Przeciwnik zadal "<<base<<" obrazen"<<std::endl;
            sleep(1000);
        }
        tour=!tour;
    }
    system(clear);
    if(hp<=0) std::cout<<"Zginales!"<<std::endl;
    else
    {
        std::cout<<"Pokonales przeciwnika!"<<std::endl;
        eve->wyswietl_bonusy();
        c_event(eve);
    }
}

void Player::c_event(Event *e)
{
    hp+=e->getHp();
    attack+=e->getAtt();
    defence+=e->getDef();
}
bool Player::Koniec()
{
    return koniec;
}
void Player::p_move()
{
    int mov=rand()%12+1;
    std::cout<<"Ruch: "<<mov<<std::endl;
    position+=mov; //tymczasowe
    for(int i=0; i<mov; i++)
    {
        p->addPos();
        sleep(500);
        system(clear);
        p->wyswietl();
        if(p->Czy()==true)
        {
            koniec=true;
            std::cout<<"Gracz dotarl do mety\n";
            break;
        }
    }

}

int Player::getHp()
{
    return hp;
}

int Player::getAtt()
{
    return attack;
}

int Player::getDef()
{
    return defence;
}
