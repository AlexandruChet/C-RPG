#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef unsigned int uint;

class Obj
{
private:
    uint health;
    string name;
    uint speed;
    float height;
    float weight;
    uint strength;

protected:
    int chance()
    {
        uint roll = rand() % 100 + 1;
        if (roll <= 80)
            return strength;
        else if (roll <= 90)
            return strength + (strength * 50 / 100);
        else
        {
            allStatsBoost();
            return strength;
        }
    }

    void allStatsBoost()
    {
        health += health / 10;
        strength += strength / 10;
        speed += speed / 10;
    }

public:
    Obj(uint hea, string n, uint sp, float hei, float w, uint str)
        : health(hea), name(n), speed(sp), height(hei), weight(w), strength(str) {}

    virtual ~Obj() {}
};
