#ifndef PLAYER_H
#define PLAYER_H

class Monster;
class Event;

class Player
{
    public:
        Player(int, int, int);
        void p_move();
        void battle(Monster*);
        void c_event(Event*);

    private:
        int base_hp, base_attack, base_defence; //Bazowe statystyki
        int hp, attack, defence; //statystyki
        int position; //Pozycja gracza
};

#endif // PLAYER_H
