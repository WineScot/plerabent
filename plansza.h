#include <iostream>
#include <vector>
#include "event.h"

class Plansza
{
private:
    std::vector <Event> pola;
    int playerPos;
    char mapa[50][50];

public:
    Plansza();
    void wyswietl();
    friend void generateMap(int,int,Plansza*);
};
