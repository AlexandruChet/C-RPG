#include <iostream>
#include <string>
#include <cstdlib>
#include <functional>

using namespace std;

typedef unsigned int uint;

class Obj {
private:
    uint health;
    string name;
    uint speed;
    float height;
    float weight;
    uint strength;

protected:
    int chance() {
        uint roll = rand() % 100 + 1;
        if (roll <= 80)
            return strength;
        else if (roll <= 90)
            return strength + (strength * 50 / 100);
        else {
            allStatsBoost();
            return strength;
        }
    }

    void allStatsBoost() {
        health += health / 10;
        strength += strength / 10;
        speed += speed / 10;
    }

public:
    Obj(uint hea, string n, uint sp, float hei, float w, uint str)
        : health(hea), name(n), speed(sp), height(hei), weight(w), strength(str) {}

    string getName() const { return name; }
    uint getHealth() const { return health; }
    void setHealth(int h) { health = (h < 0 ? 0 : (uint)h); }
    uint getStrength() const { return strength; }

    virtual void attack(Obj &target) = 0;
    virtual void walking() = 0;
    virtual void recovery() = 0;
    virtual void strong() = 0;

    virtual ~Obj() {}
};

class Hero : public Obj {
public:
    Hero(string n, float hei, float w)
        : Obj(100, n, 50, hei, w, 100) {}

    void attack(Obj &target) override {
        uint damage = chance();
        target.setHealth(target.getHealth() - damage);
        cout << getName() << " attack! Target health: " << target.getHealth() << endl;
    }

    void walking() override {
        cout << getName() << " walking" << endl;
    }

    void recovery() override {
        setHealth(getHealth() + 30);
        cout << getName() << " recovered. New health: " << getHealth() << endl;
    }

    void strong() override {
        cout << getName() << " makes stronger" << endl;
    }
};

class registration {
protected:
    uint password;
    string name;

    void cipher() {
        hash<string> hasher;
        size_t hashed = hasher(to_string(password));
        cout << "Your password hash: " << hashed << endl;
    }

public:
    registration(uint p, string n) : password(p), name(n) {}

    virtual string getName() { return name; }

    virtual ~registration() {}
};

class reg : public registration {
public:
    reg(uint p, string n) : registration(p, n) {}

    string getName() override {
        cout << "Write your Password: ";
        cin >> password;
        cipher();
        return name;
    }
};

int main() {
    Hero h("Arthur", 1.8f, 75.0f);
    Hero enemy("Dark Lord", 2.0f, 90.0f);

    h.attack(enemy);
    enemy.recovery();

    reg user(1234, "Player1");
    user.getName();

    return 0;
}
