#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    public:
        player();
        virtual ~player();
        void p_move();
        void c_event();

    private:
        int hp,attack,defence;


};

#endif // PLAYER_H
