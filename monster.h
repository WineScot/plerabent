#ifndef MONSTER_H
#define MONSTER_H


class Monster
{
    public:
        Monster();
        virtual ~Monster();
        int hp, attack, defence;
        string name;
    private:
};

#endif // MONSTER_H
