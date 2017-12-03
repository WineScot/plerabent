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
    sleep(2000);
    while(hp>0 && monsterHp>0)
    {
        int base=rand()%6+1; //rzut kostką
        if(tour)
        {
            int w_attack = attack;
            system(clear);
            showstats();
            std::cout<<"\n";
            eve->getM()->showstats(monsterHp);
            std::cout<<"Twoja tura!"<<std::endl;
            sleep(500);
            WAIT;
            std::cout<<"Rzut kostką: "<<base<<std::endl;
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
            std::cout<<"Zadałeś "<<base<<" obrażeń"<<std::endl;
            sleep(1500);
        }
        else
        {
            system(clear);
            showstats();
            std::cout<<"\n";
            eve->getM()->showstats(monsterHp);
            std::cout<<"Tura przeciwnika!"<<std::endl;
            sleep(500);
            std::cout<<"Rzut kostką: "<<base<<std::endl;
            base+=monsterAtt-defence;
            base=std::max(base,1);
            hp-=base;
            std::cout<<"Przeciwnik zadał "<<base<<" obrażeń"<<std::endl;
            c_damage+=base;
            WAIT;
        }
        tour=!tour;
    }
    system(clear);
    if(hp<=0)
    {

        std::cout<<"Zginąłeś!"<<std::endl;
        koniec=true;
        return;
    }
    else
    {
        std::cout<<"Pokonałeś przeciwnika!"<<std::endl;
        eve->wyswietl_bonusy();
        c_event(eve);
        if(heal)
        {
            std::cout<<"Umiejętność druida";
            for(int i=0;i<3;i++)
            {
                sleep(1000);
                std::cout<<".";
            }
            std::cout<<"\n";
            int l_heal=rand()%100+1;
            if(l_heal<30)
            {
                hp=hp+c_damage/2; //jest 30% szans na odnowienie 50% obrazen
                std::cout<<c_damage/2<<" zostało odnowione\n";
            }
            else
                std::cout<<"Użycie umiejętności się nie powiodło :(\n";

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
        if(!(rand()%5)) qte(this);
        p->wyswietl();
        showstats();
        if(p->Czy()==true)
        {
            koniec=true;
            std::cout<<"Gracz dotarł do mety\n";
            break;
        }
    }

}

void Player::showstats()
{
    std::cout<<"Twoje statystyki:"<<std::endl;
    std::cout<<"Punkty życia: "<<hp<<std::endl;
    std::cout<<"Atak: "<<attack<<std::endl;
    std::cout<<"Obrona: "<<defence<<std::endl;
}

void Player::odejmijhp(int val)
{
    hp-=val;
    if(hp<=0)
        koniec=true;
}

void Player::addattack(int val)
{
    attack+=val;
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

bool Player::getDodge()
{
    return dodge;
}


