#include "event.h"
#include "monster.h"

std::string Event::Event_plots[];


Event::Event( int a, int b, int i )
{
    x = a;
    y = b;
}

int Event::getHp()
{
    return hp;
}

int Event::getAtt()
{
    return attack;
}

int Event::getDef()
{
    return defence;
}

Monster* Event::getM()
{
    return &m;
}

void Event::wyswietl() //tymczasowe
{
    std::cout<<plot<<std::endl;
}
