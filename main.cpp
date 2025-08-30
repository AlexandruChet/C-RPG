#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Character
{
protected:
    float health;
    float speed;
    float strength;

public:
    Character(float h, float s, float str) : health(h), speed(s), strength(str) {}

    virtual void attack(Character &target) = 0;
    virtual void heal(float amount)
    {
        health += amount;
        if (health > 100)
            health = 100;
        cout << "Healed for " << amount << ", health now " << health << endl;
    }
    virtual void walk(float max_speed)
    {
        if (speed > max_speed)
            speed = max_speed;
        cout << "Walking with speed " << speed << endl;
    }

    float getHealth() { return health; }
};

class Hero : public Character
{
public:
    Hero() : Character(100, 15.5, 16) {}

    void attack(Character &target) override
    {
        int chance = rand() % 100;
        if (chance < 80)
        {
            target.heal(-strength);
            cout << "Hero attacks! Target health: " << target.getHealth() << endl;
        }
        else
        {
            cout << "Hero missed!" << endl;
        }
    }

    void kill(Character &target)
    {
        if (target.getHealth() <= 0)
        {
            cout << "Enemy is killed" << endl;
            health += 15;
            speed += 6;
            strength += 5;
        }
    }

    void heal(float amount) override
    {
        Character::heal(amount);
    }

    void walk(float max_speed) override
    {
        Character::walk(max_speed);
    }
};

class Enemy : public Character
{
public:
    Enemy() : Character(50, 7, 5) {}

    void attack(Character &target) override
    {
        int chance = rand() % 100;
        if (chance < 50)
        {
            target.heal(-strength);
            cout << "Enemy attacks! Target health: " << target.getHealth() << endl;
        }
        else
        {
            cout << "Enemy missed!" << endl;
        }
    }

    void heal(float amount) override
    {
        Character::heal(amount);
    }

    void walk(float max_speed) override
    {
        Character::walk(max_speed);
    }
};

class Boss : public Character
{
public:
    Boss() : Character(150, 12, 20) {}

    void attack(Character &target) override
    {
        int chance = rand() % 100;
        if (chance < 70)
        {
            target.heal(-strength);
            cout << "Boss attacks! Target health: " << target.getHealth() << endl;
        }
        else
        {
            cout << "Boss missed!" << endl;
        }
    }

    void heal(float amount) override
    {
        Character::heal(amount);
    }

    void walk(float max_speed) override
    {
        Character::walk(max_speed);
    }
};

int main()
{
    srand(time(0));

    Hero hero;
    Enemy enemy;
    Boss boss;

    cout << "Initial health:\n";
    cout << "Hero: " << hero.getHealth() << "\n";
    cout << "Enemy: " << enemy.getHealth() << "\n";
    cout << "Boss: " << boss.getHealth() << "\n\n";

    hero.walk(20);
    hero.attack(enemy);
    hero.heal(20);

    cout << "\n";

    enemy.walk(10);
    enemy.attack(hero);
    enemy.heal(10);

    cout << "\n";

    boss.walk(15);
    boss.attack(hero);
    boss.attack(enemy);
    boss.heal(15);

    cout << "\nFinal health:\n";
    cout << "Hero: " << hero.getHealth() << "\n";
    cout << "Enemy: " << enemy.getHealth() << "\n";
    cout << "Boss: " << boss.getHealth() << "\n";

    return 0;
}
