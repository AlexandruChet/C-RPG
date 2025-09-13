#include <iostream>
#include <string>
#include <cstdlib>
#include <functional>

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

    virtual void attack() = 0;
    virtual void walking() = 0;
    virtual void recovery() = 0;
    virtual void strong() = 0;
    virtual string getName() = 0;

    virtual ~Obj() {}
};

class registration
{
protected:
    uint password;
    string name;

    void cipher()
    {
        hash<string> hasher;
        size_t hashed = hasher(to_string(password));
        cout << "Your password hash: " << hashed << endl;
    }

public:
    registration(uint p, string n) : password(p), name(n) {}

    virtual string getName() { return name; }

    virtual ~registration() {}
};

class reg : public registration
{
public:
    reg(uint p, string n) : registration(p, n) {}

    void getName() override
    {
        cout << "Write your Password: ";
        cin >> password;
        cipher();
    }
};
