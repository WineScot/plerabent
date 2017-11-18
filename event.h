// #include <iostream>
#include <string>
#include "monster.h"

class Event
{
private:
    static std::string tab[100];
    std::string plot;
    Monster m;
    int x, y;
    int hp, attack, defence; //bonusy
public:
    Event(int,int,int);//( x, y, indesk pola )
    friend void init();
};
