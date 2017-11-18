#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "monster.h"

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

int main()
{
    std::string a="Monsters.txt";
    main_init(a);
    Monster mo;
    mo.test();
}
