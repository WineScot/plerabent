#include "funkcje.h"
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <string>
#include <fstream>

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
    std::ifstream plik( path.c_str(), std::ios::in );
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

void qte()
{
    std::cout<<"Pułapka!!!\nNaciskaj szybko pokazywane klawisze!\n";
    sleep(1500);
    int now=GetTickCount(); //obecny czas
    srand(now);
    int letters=5;
    while(letters--)
    {
        int now=GetTickCount(); //obecny czas
        char sign=(char)(rand()%26+(int)'a');
        std::cout<<sign<<std::endl;
        if(getch()==sign)
        {
            if(GetTickCount()-now>=2000) break;
        }
        else break;
    }
    if(letters>=0) std::cout<<"Źle!"<<std::endl;
    else std::cout<<"Ominięto pułapkę!"<<std::endl;
    sleep(1500);
    system(clear);
}



#ifndef WIN32
void sleep( int i )
{
    usleep(1000*i);
}
#endif // WIN32
