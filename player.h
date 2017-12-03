#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Monster;
class Event;
class Plansza;

class Player
{
    protected:
         bool heal;
         bool dodge;
         bool koniec;
        int critical;//szansa na trafienie krytyczne
        int hp, attack, defence; //statystyki
        int position; //Pozycja gracza
        std::string name;
    public:
        //Player(int, int, int, Plansza*);
        Player(Plansza*);
        void ustawimie(); // gracz podaje imię
        void p_move();
        void battle(Event*);
        void BossBattle();
        void c_event(Event*);
        void odejmijhp(int);
        void addattack(int);
        void showstats(); //pokazuje statystyki gracza
        int getHp();
        int getAtt();
        int getDef();
        bool getDodge();
        bool Koniec();
        Plansza *p;
};

#endif // PLAYER_H
