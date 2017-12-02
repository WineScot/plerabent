#ifndef PLAYER_H
#define PLAYER_H

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
    public:
        Player(Plansza*);
        void p_move();
        void battle(Event*);
        void c_event(Event*);
        int getHp();
        int getAtt();
        int getDef();
        bool Koniec();
        Plansza *p;
};

#endif // PLAYER_H
