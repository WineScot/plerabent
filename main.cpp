#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "monster.h"
#include "event.h"
#include "player.h"
#include "plansza.h"

void main_init(std::string path)
{
    std::string s;
    int a=0;
    std::fstream plik( path.c_str(), std::ios::in );
    while( getline( plik, s ) )
    {
        a++;
        Monster::monsters[a].name=s;
        getline( plik, s );
        int b= atoi(s.c_str());
        Monster::monsters[a].hp=b;
        getline( plik, s );
        b=atoi(s.c_str());
        Monster::monsters[a].attack=b;
        getline( plik, s );
        b=atoi(s.c_str());
        Monster::monsters[a].defence=b;
    }
    Monster::Num_monst=a;
}

void Event_init(std::string path)
{
    std::string s;
    std::fstream plik( path.c_str(), std::ios::in );
    std::string *tab=Event::Event_plots;
    int a=0;
    while( getline( plik, s ) )
    {
        a++;
        *tab = s;
        tab++;
    }
    Event::Num_event=a;
}

void init()
{
    main_init("Monsters.txt");
    Event_init("Events.txt");
}

int main()
{
    init();
    Plansza mapa;
    Player player(1,1,1,&mapa);
    mapa.wyswietl();
    for(;;)
    {
        system("cls");
        mapa.wyswietl();
        player.p_move();
        system("pause");
    }
    return 0;
}
