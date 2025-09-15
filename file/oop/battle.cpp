#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

class Character // main class
{
protected:
    float strength;
    float speed;
    string name;
    float health;
    float defenseValue; // renamed to avoid conflict

public:
    Character(float str, float sp, string n, float heal, float def)
        : strength(str), speed(sp), name(n), health(heal), defenseValue(def) {} // my constructor

    virtual void attack(Character &target) = 0;
    virtual void defense() = 0;
    virtual void recovery() = 0;
    virtual void miss() = 0;
    virtual void random(Character &target) = 0; // my main virtual func.

    void takeDamage(float dmg) { health -= dmg; }
    void addDefense(float value) { defenseValue += value; }
    void addStrength(float value) { strength += value; }
    void heal(float value) { health += value; } // help to main functions

    float getHealth() const { return health; } // this is getter for health
};

class Hero : public Character
{
private:
    int mana;

public:
    Hero() : Character(50, 100, "Hero", 100, 30), mana(100) {} // constructor

    void attack(Character &target) override
    {
        int r = rand() % 100; // random %
        if (r == 80)
            target.takeDamage(strength);
        else
            target.takeDamage(strength * 1.5); // attack func
    }

    void defense() override // defense func
    {
        addDefense(30);
    }

    void recovery() override // recovery
    {
        heal(30);
    }

    void miss() override
    {
        // I ll make that then
    }

    void random(Character &target) override // random func
    {
        vector<string> perks = {"Defense", "Attack", "Health", "Mana", "", ""}; // perks
        int index = rand() % perks.size();
        string perk = perks[index];

        if (perk == "Defense") // verification
            target.addDefense(100);
        else if (perk == "Attack")
            target.addStrength(50);
        else if (perk == "Health")
            target.heal(100);
        else if (perk == "Mana")
            mana += 100;
        else
            takeDamage(5);
    }
};

class Enemy : public Character
{
private:
    int mana;

public:
    Enemy() : Character(35, 60, "Enemy", 300, 10), mana(50) {} // constructor

    void attack(Character &target) override
    {
        int r = rand() % 100;
        if (r == 80)
            target.takeDamage(strength);
        else
            target.takeDamage(strength * 1.1);
    }

    void defense() override
    {
        addDefense(10);
    }

    void recovery() override
    {
        heal(15);
    }

    void miss() override
    {
        // I'll finish it later.
    }

    void random(Character &target) override
    {
        int random_chance = rand() % 4 + 1;
        if (random_chance == 1)
            attack(target);
        else if (random_chance == 2)
            defense();
        else if (random_chance == 3)
            recovery();
        else if (random_chance == 4)
            miss();
        else
            printf("Error");
    }
};

void game_play()
{
    srand(static_cast<unsigned int>(time(0))); // random seed
    Hero hero;
    Enemy enemy;

    char command;
    cout << "======================================" << endl;
    cout << "          Welcome to the Game!          " << endl;
    cout << "======================================" << endl;
    cout << "|  A - Attack                        |" << endl;
    cout << "|  B - Defense                      |" << endl;
    cout << "|  C - Recovery                      |" << endl;
    cout << "|  D - Miss                         |" << endl;
    cout << "======================================" << endl;

    while (true)
    {
        cout << "Enter your command: ";
        cin >> command; // gameplay

        if (command == 'A')
        {
            hero.attack(enemy);
        }
        else if (command == 'B')
        {
            hero.defense();
        }
        else if (command == 'C')
        {
            hero.recovery();
        }
        else if (command == 'D')
        {
            hero.miss();
        }
        else
        {
            cout << "Invalid command!" << endl;
            continue;
        }

        enemy.random(hero);

        if (hero.getHealth() <= 0)
        {
            cout << "You lost!" << endl;
            break;
        }
        else if (enemy.getHealth() <= 0)
        {
            cout << "You won!" << endl;
            break;
        }
    }
}

int main()
{
    game_play();
    return 0;
}
