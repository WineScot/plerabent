#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <string>
#include "monster.h"

class Event
{
private:
    static std:: string Event_plots[100];
    std:: string plot;
    Monster m;
    int x, y;
    int hp, attack, defence; //bonusy
public:
    Event(int,int,int);//( x, y, indesk pola )
    friend void Event_init(std:: string);
    void wyswietl();
};


#endif // EVENT_H
