#include <iostream>
#include <string>

using namespace std;

class Character
{
private:
    float strenght;
    float speed;
    string name;
    float health;
    float defense;

public:
    class Character(float str, float sp, string n, float hea, float def)
        : strenght(str), speed(sp), name(n), health(hea), defense(def) {}

    virtual void attack() = 0;
    virtual void defense() = 0;
    virtual void recovery() = 0;
    virtual void random() = 0;
}