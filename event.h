// #include <iostream>
#include <string>
#include "monster.h"

using namespace std;

class Event
{
private:
    static string tab[100];
    string plot;
    Monster m;
    int x, y;
    int hp, attack, defence; //bonusy
public:
    Event(int,int,int);//( x, y, indesk pola )
    friend void init();
};
