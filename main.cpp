#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

// headers
#include "monster.h"
#include "event.h"
#include "player.h"
#include "plansza.h"
#include "funkcje.h"

int main()
{
    main_init("Monsters.txt");
    Event_init("Events.txt");
    Plansza mapa;
    Player* player=&p;
    mapa.wyswietl();
    while(!player->Koniec())
    {
        system("cls");
        mapa.wyswietl();
        sleep(500);
        player->p_move();
        system("pause");
        mapa.action(player);
        system("pause");
        if(player->getHp()<0) break;
    }
    return 0;
}
