#include <iostream>
#include <vector>
#include "event.h"

class Plansza
{
private:
    Event* pola[500];
    int playerPos;
    char mapa[50][50];
    bool czy=false;

public:
    Plansza();
    void wyswietl();
    friend void generateMap(int,int,Plansza*);
    void addPos();
    bool Czy();
    void zmien();
    void action(Player*);
    void Test();
};
