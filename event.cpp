#include "event.h"
#include "monster.h"
#include <ctime>
#include <cstdlib>

#include<windows.h>

std::string Event::Event_plots[];

int Event::Num_event;

Event::Event(int x, int y, int ind)
{
    srand(ind);
    this->x=x;
    this->y=y;
    int id=rand()%Num_event;
    plot=Event_plots[id];
    m=Monster();
    hp=(rand()%8)+1;
    attack=(rand()%8)+1;
    defence=(rand()%8)+1;
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
    std::cout<<plot<<std::endl;
    std::cout<<"Przed toba pojawia sie: "<<m.getName()<<std::endl;
    std::cout<<"Punkty zycia: "<<m.getHp()<<std::endl;
    std::cout<<"Atak: "<<m.getAtt()<<std::endl;
    std::cout<<"Obrona: "<<m.getDef()<<std::endl;
}

void Event::wyswietl_bonusy()
{
    std::cout<<"Otrzymujesz nastepujace bonusy:"<<std::endl;
    std::cout<<"Punkty zycia: "<<hp<<std::endl;
    std::cout<<"Atak: "<<attack<<std::endl;
    std::cout<<"Obrona: "<<defence<<std::endl;
}
