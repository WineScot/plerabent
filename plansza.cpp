#include <cstdlib>
#include <stack>
#include <ctime>
#include <windows.h>
#include "plansza.h"

const int N = 20; // rozmiar mapy
bool odw[N][N];
std::stack < std::pair<int,int> > path;
bool done;

void generateMap( int x, int y )
{
    if(x == N-1 && y == N-1)
        done = true;

    odw[x][y] = true;
    std::pair<int,int> edges[4] = { {-1,0}, {1,0}, {0,1}, {0,-1} };
    // losowanie kolejności odwiedzanych wierzchołków
    for(int i=0; i<8; i++)
    {
        int a = rand()%4;
        int b = rand()%4;
        swap(edges[a],edges[b]);
    }

    for(int i=0; i<4; i++)
    {
        int p = edges[i].first;
        int q = edges[i].second;
        if( x+p < N && x+p > 0 && y+q < N && y+q > 0 && !odw[x+p][y+q] )
        {
            if(!done)
            path.push( std::make_pair( x+p, y+q ) );

            std::vector < std::pair<int,int> > f;
            for(int k=0; k<4; k++)
            {
                int a = edges[k].first;
                int b = edges[k].second;
                if( !odw[x+a][y+b] )
                {
                    odw[x+a][y+b] = true;
                    f.push_back( std::make_pair(x+a, y+b) );
                }
            }

            generateMap(x+p, y+q);

            for(int k=0; k<f.size(); k++)
            {
                int a = f[k].first;
                int b = f[k].second;
                if( !(a == x+p && b == q+b) )
                odw[a][b] = false;
            }

            if(done) return;
            path.pop();
        }
    }
}

Plansza::Plansza()
{
    path.push( std::make_pair(1,1) );
    playerPos=0;
    // mapa init
    for(int i=0; i<N+1; i++)
        for(int j=0; j<N+1; j++)
            mapa[j][i] = ' ';

    srand(time(NULL));
    generateMap(1,1);

    while(!path.empty())
    {
        int a = path.top().first;
        int b = path.top().second;
        pola[ path.size()-1 ] =new Event(a,b,(int)(path.size()-1));
        //std::cout<<pola[path.size()-1]->GetPlot()<<std::endl;
        mapa[a][b] = '#';
        path.pop();
    }
    mapa[1][1] = '#';
    mapa[ pola[playerPos]->X() ][ pola[playerPos]->Y() ] = 'P';
}

void Plansza::wyswietl()
{
    for(int i=0; i<N+1; i++)
    {
        for(int j=0; j<N+1; j++)
            std::cout<<mapa[j][i];
        std::cout<<std::endl;
    }
}

void Plansza::addPos()
{
    mapa[ pola[playerPos]->X() ][ pola[playerPos]->Y() ] = '#';

    playerPos += 1;

    mapa[ pola[playerPos]->X() ][ pola[playerPos]->Y() ] = 'P';
    if (pola[playerPos]->X()== N-1 && pola[playerPos]->Y() == N-1)
    {
        czy=true;
        return;
    }
}
bool Plansza::Czy()
{
    return czy;
}
void Plansza::zmien()
{
    czy=false;
}
void Plansza::action(Player* player)
{
    pola[playerPos]->wyswietl();
    Sleep(2000);
    player->battle(pola[playerPos]);
}
void Plansza::Test()
{
    for(int i=0;i<5;i++)
    {
        std::cout<<pola[i]->GetPlot()<<std::endl;
    }
    return;
}
