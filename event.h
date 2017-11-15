#include "monster.h"

class Event
{
private:
    static string tab[100];
    string plot;
    Monster m;
    int hp, attack, defence; //bonusy
public:
    Event(int,int,int);//( x, y, indesk pola )
    friend void init();
};
