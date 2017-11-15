
#include "monster.h"

class Event
{
private:
    static string tab[100];
    string plot;
    Monster m;
    int x, y;
    int hp, attack, defence; //bonusy
public:
    friend void init();
};
