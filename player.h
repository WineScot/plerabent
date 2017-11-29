#ifndef PLAYER_H
#define PLAYER_H

class Monster;
class Event;
class Plansza;

class Player
{
    public:
        //Player(int, int, int, Plansza*);
        void p_move();
        void battle(Monster*);
        void c_event(Event*);
        bool Koniec();
        Plansza *p;

    protected:
        //int base_hp, base_attack, base_defence; //Bazowe statystyki
        int hp, attack, defence; //statystyki
        int position; //Pozycja gracza
        bool koniec=false;
};

#endif // PLAYER_H
