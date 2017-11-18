#include "monster.h"


Monster::Monster()
{


}

void init( std::string path, std::string *tab )
{
    std::string s;
    std::fstream plik( path.c_str(), std::ios::in );
    while( getline( plik, s ) )
    {
        *tab = s;
        tab++;
    }
}
