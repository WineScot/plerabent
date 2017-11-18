#include <cstdlib>
#include <stack>
#include "plansza.h"

using namespace std;

const int N = 15; // rozmiar mapy
bool odw[N][N];
stack < pair<int,int> > path;
bool done;

void generateMap( int x, int y )
{
    if(x == N-1 && y == N-1)
    {
        cout<<"Wypisujemy ścieżkę"<<endl;
        done = true;
    }

    odw[x][y] = true;
    pair<int,int> edges[4] = { {-1,0}, {1,0}, {0,1}, {0,-1} };
    // losowanie kolejności odwiedzanych wieżhołków
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
            path.push( make_pair( x+p, y+q ) );

            vector < pair<int,int> > f;
            for(int k=0; k<4; k++)
            {
                int a = edges[k].first;
                int b = edges[k].second;
                if( !odw[x+a][y+b] && a != p && b != q )
                {
                    odw[x+a][y+b] = true;
                    f.push_back( make_pair(x+a, y+b) );
                }
            }

            generateMap(x+p, y+q);

            for(int k=0; k<f.size(); k++)
            {
                int a = f[k].first;
                int b = f[k].second;
                odw[a][b] = false;
            }

            if(done) return;
            path.pop();
        }
    }
}

Plansza::Plansza()
{
    // mapa init
    for(int i=0; i<N+1; i++)
        for(int j=0; j<N+1; j++)
            mapa[j][i] = ' ';

    srand(time(NULL));
    generateMap(1,1 );

    while(!path.empty())
    {
        int a = path.top().first;
        int b = path.top().second;
        mapa[a][b] = '.';
        path.pop();
    }
    mapa[1][1] = '.';

    // for(int i=0; i<N; i++)
    // {
    //     pola.push_back( Event(i,0,i) );
    //     mapa[i][0] = '#';
    // }
}

void Plansza::wyswietl()
{
    for(int i=0; i<N+1; i++)
    {
        for(int j=0; j<N+1; j++)
            cout<<mapa[j][i];
        cout<<endl;
    }
}
