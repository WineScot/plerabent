#include <iostream>
#include "plansza.h"

using namespace std;

Plansza::Plansza()
{
    // mapa init
    for(int i=0; i<15; i++)
        for(int j=0; j<15; j++)
            mapa[j][i] = '.';

    for(int i=0; i<15; i++)
    {
        pola.push_back( Event(i,0,i) );
        mapa[i][0] = '#';
    }
}

void Plansza::wyswietl()
{
    for(int i=0; i<15; i++)
    {
        for(int j=0; j<15; j++)
            cout<<mapa[j][i];
        cout<<endl;
    }
}
