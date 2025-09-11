#include <iostream>
#include <string>

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
    int strength;

public:
    Obj(uint hea, string n, uint sp, float hei, float w, int str)
        : health(hea), name(n), speed(sp), height(hei), weight(w), strength(str) {}

    virtual void attack() = 0;
    virtual void walking() = 0;
    virtual void recovery() = 0;
    virtual void strong() = 0;
    virtual string getName() = 0;

    virtual ~Obj() {}
};
