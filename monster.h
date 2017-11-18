#include <string>

struct m
{
    std::string name;
    int hp,attack,defence;
};

class Monster
{
private:
    int hp, attack, defence;
    std::string name;
    static int Num_monst;
    static m monsters[1000000];
public:
    friend void main_init(std::string);
    void test();
    Monster();
};

