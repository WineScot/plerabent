#include <iostream>
#include <vector>
#include "event.h"

using namespace std;

class Plansza
{
private:
    vector <Event> pola;
    int playerPos;
    char mapa[50][50];

public:
    Plansza();
    void wyswietl();
};
