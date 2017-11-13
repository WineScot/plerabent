#ifndef MONSTER_H
#define MONSTER_H

class Monster
{
private:
    Monster();
    virtual ~Monster();
    int hp, attack, defence;
    string name;
public:
    friend void init();
};

#endif // MONSTER_H
