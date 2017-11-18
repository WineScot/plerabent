#include "event.h"

using namespace std;

string Event::Event_plots[];

Event::Event( int a, int b, int i )
{
    x = a;
    y = b;
}

void Event::wyswietl() //tymczasowe
{
    cout<<plot<<endl;
}
