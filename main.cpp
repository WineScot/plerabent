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
#include "warrior.h"
#include "thief.h"
#include "druid.h"

int main()
{
    main_init("Monsters.txt");
    Event_init("Events.txt");
    Plansza mapa;
    Player* player;
    std::cout<<"Wybierz klase:\n 1.Wojownik\n 2.Druid\n 3.Zlodziej\n";
    int liczba=0;
    std::cin>>liczba;
    switch(liczba)
    {
    case 1:
        {
            Warrior w_player(&mapa);
            player=&w_player;
            break;
        }
   case 2:
       {
            Druid d_player(&mapa);
            player=&d_player;
            break;
       }
    case 3:
        {
            Thief t_player(&mapa);
            player=&t_player;
            break;
        }

    }
    while(!player->Koniec())
    {
        system("pause");
        system("cls");
        mapa.wyswietl();
        sleep(500);
        system("pause");
        player->p_move();
        system("pause");
        if (!player->Koniec())
        mapa.action(player);
        if(player->getHp()<0) break;
    }
    return 0;
}
