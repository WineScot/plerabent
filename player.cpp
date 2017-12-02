#include "player.h"
#include <cstdlib>
#include <windows.h>
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
    srand(hp);
    int monsterHp = eve->getM()->getHp();
    int monsterAtt = eve->getM()->getAtt();
    int monsterDef = eve->getM()->getDef();
    int c_damage=0;//otrzymane obrazenia (Druid)
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
            int w_attack = attack;
            system(clear);
            std::cout<<"Twoja tura!"<<std::endl;
            sleep(500);
            WAIT;
            std::cout<<"Rzut kostka: "<<base<<std::endl;
            if(critical>0)
            {
              int w_crit=rand()%100+1;
              if(w_crit<=critical)
              {
                    w_attack*=2;
                    std::cout<<"TRAFIENIE KRYTYCZNE!\n";
              }
            }
            base+=w_attack-monsterDef;
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
            c_damage+=base;
            sleep(1000);
        }
        tour=!tour;
    }
    system(clear);
    if(hp<=0)
    {
        std::cout<<"Zginales!"<<std::endl;
        return;
    }
    else
    {
        std::cout<<"Pokonales przeciwnika!"<<std::endl;
        eve->wyswietl_bonusy();
        c_event(eve);
        if(heal)
        {
            std::cout<<"Umiejetnosc druida";
            for(int i=0;i<3;i++)
            {
                Sleep(1000);
                std::cout<<".";
            }
            std::cout<<"\n";
            int l_heal=rand()%100+1;
            if(l_heal<30)
            {
                hp=hp+c_damage/2; //jest 43% szans na odnowienie 50% obrazen
                std::cout<<c_damage/2<<" zostało odnowione\n";
            }
            else
                std::cout<<"Uzycie umiejetnosci sie nie powiodlo :(\n";

        }
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
        if(!(rand()%5)) qte();
        p->wyswietl();
        if(p->Czy()==true)
        {
            koniec=true;
            std::cout<<"Gracz dotarl do mety\n";
            return;
        }
    }

}

void Player::odejmijhp(int val)
{
    hp-=val;
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

int Player::stat()
{
    std::cout<<"punkty życia: "<<hp<<std::endl;
    std::cout<<"atak: "<<attack<<std::endl;
    std::cout<<"obrona: "<<defence<<std::endl;
}


