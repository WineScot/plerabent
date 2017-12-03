#include <iostream>
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
    system("chcp 65001");
    system(clear);
    main_init("Monsters.txt");
    Event_init("Events.txt");
    Plansza mapa;
    Player* player;
    std::cout<<"Wybierz klasę:\n 1.Wojownik\n 2.Druid\n 3.Złodziej\n";
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
    player->ustawimie();
    player->BossBattle();
    while(!player->Koniec())
    {
        WAIT;
        system(clear);
        mapa.wyswietl();
        sleep(500);
        player->p_move();
        WAIT;
        if (!player->Koniec())
        mapa.action(player);
        if(player->getHp()<0) break;
    }
    return 0;
}
