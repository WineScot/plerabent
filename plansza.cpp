#include "plansza.h"
#include "event.h"

using namespace std;

Plansza::Plansza()
{
    for(int i=0; i<15; i++)
    {
        pola.push_back( Event(0,i,i) );
    }
}
