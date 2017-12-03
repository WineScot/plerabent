#include "event.h"
#include "monster.h"
#include "funkcje.h"
#include <ctime>
#include <cstdlib>

std::string Event::Event_plots[];

int Event::Num_event;

Event::Event(int x, int y, int ind)
{
    this->x=x;
    this->y=y;
    srand(ind);
    int id=rand()%Num_event;
    plot=Event_plots[id];
    m=Monster();
    hp=(rand()%8)+1;
    attack=(rand()%8)+1;
    defence=(rand()%8)+1;
}

void Event::ustaw_potwora(Monster en)
{
    m=en;
}

int Event::getHp()
{
    return hp;
}

int Event::getAtt()
{
    return attack;
}
std::string Event::GetPlot()
{
    return plot;
}
int Event::getDef()
{
    return defence;
}

Monster* Event::getM()
{
    return &m;
}

int Event::X()
{
    return x;
}

int Event::Y()
{
    return y;
}

void Event::wyswietl()
{
    std::cout<<plot.c_str()<<std::endl;
    std::cout<<"Przed tobą pojawia się: "<<m.getName().c_str()<<std::endl;
    std::cout<<"Punkty życia: "<<m.getHp()<<std::endl;
    std::cout<<"Atak: "<<m.getAtt()<<std::endl;
    std::cout<<"Obrona: "<<m.getDef()<<std::endl;
}

void Event::wyswietl_bonusy()
{
    std::cout<<"Otrzymujesz następujące bonusy:"<<std::endl;
    std::cout<<"Punkty życia: "<<hp<<std::endl;
    std::cout<<"Atak: "<<attack<<std::endl;
    std::cout<<"Obrona: "<<defence<<std::endl;
}
