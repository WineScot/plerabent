#ifndef PLAYER_H
#define PLAYER_H

class Monster;
class Event;
class Plansza;

class Player
{
    protected:
        //int base_hp, base_attack, base_defence; //Bazowe statystyki
        int hp, attack, defence; //statystyki
        int position; //Pozycja gracza
        bool koniec=false;
    public:
        //Player(int, int, int, Plansza*);
        Player(Plansza*);
        void p_move();
        void battle(Monster*);
        void c_event(Event*);
        int getHp();
        int getAtt();
        int getDef();
        bool Koniec();
        Plansza *p;
};

#endif // PLAYER_H
