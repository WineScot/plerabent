#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <string>
#include "monster.h"

class Event
{
private:
    static int Num_event;
    static std::string Event_plots[100];
    std::string plot;
    Monster m;
    int hp, attack, defence; // bonusy
    int x, y; //pozycje
public:
    Event(int,int,int); // ( x, y, numer pola )
    friend void Event_init(std::string);
    void wyswietl();
    void wyswietl_bonusy();
    void ustaw_potwora(Monster); //do walki z bossem
    Monster* getM();
    int getHp();
    int getAtt();
    int getDef();
    std::string GetPlot();
    int X();
    int Y();
};


#endif // EVENT_H
