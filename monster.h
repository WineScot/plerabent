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
    friend void init();
};

#endif // MONSTER_H
