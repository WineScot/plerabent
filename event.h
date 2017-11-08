#include "monster.h"

struct ev
{
    string name, plot;
};

class Event
{
private:
    static ev tab[100];
    string name, plot;
    Monster m;
    int hp, attack, defence; //bonusy
public:
    init();
};
