#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <memory>

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
        cout << "Healed for " << amount << ", health is now " << health << endl;
    }

    virtual void walk(float max_speed)
    {
        if (speed > max_speed)
            speed = max_speed;
        cout << "Walking with speed " << speed << endl;
    }

    float getHealth() const { return health; }
};

class Hero : public Character
{
public:
    int experience;

    Hero() : Character(100, 15.5, 16), experience(0) {}

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
            cout << "Enemy is killed!" << endl;
            health += 15;
            speed += 6;
            strength += 5;
            experience += 50;
        }
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
};

class Item
{
protected:
    string name;

public:
    Item(const string &n) : name(n) {}
    virtual ~Item() = default;

    virtual void use(Character &user, Character *target = nullptr) = 0;
    string getName() const { return name; }
};

class Sword : public Item
{
    int damage;

public:
    Sword(int dmg) : Item("Sword"), damage(dmg) {}

    void use(Character &user, Character *target = nullptr) override
    {
        if (target)
        {
            target->heal(-damage);
            cout << "Hero deals " << damage
                 << " damage with sword! Target health: "
                 << target->getHealth() << " HP.\n";
        }
    }
};

class Potion : public Item
{
    int healAmount;

public:
    Potion(int h) : Item("Potion"), healAmount(h) {}

    void use(Character &user, Character *target = nullptr) override
    {
        user.heal(healAmount);
        cout << "Hero drinks potion and restores " << healAmount
             << " HP! Current health: " << user.getHealth() << "\n";
    }
};

class Bow : public Item
{
    int damage;
    int arrows;

public:
    Bow(int dmg, int arr) : Item("Bow"), damage(dmg), arrows(arr) {}

    void use(Character &user, Character *target = nullptr) override
    {
        if (arrows > 0 && target)
        {
            arrows--;
            target->heal(-damage);
            cout << "Hero shoots bow: " << damage
                 << " damage. Target health: " << target->getHealth()
                 << " HP. Arrows left: " << arrows << "\n";
        }
        else
        {
            cout << "No arrows left!\n";
        }
    }
};

class Inventory
{
    vector<shared_ptr<Item>> slots;

public:
    void addItem(shared_ptr<Item> item)
    {
        slots.push_back(item);
    }

    void showInventory() const
    {
        cout << "=== Inventory ===\n";
        for (size_t i = 0; i < slots.size(); i++)
        {
            cout << i + 1 << ". " << slots[i]->getName() << "\n";
        }
    }

    void useItem(int index, Character &user, Character *target = nullptr)
    {
        if (index < 1 || index > (int)slots.size())
        {
            cout << "Invalid slot!\n";
            return;
        }
        slots[index - 1]->use(user, target);
    }
};

int main()
{
    srand(time(0));

    Hero hero;
    Enemy enemy;
    Boss boss;

    Inventory inv;
    inv.addItem(make_shared<Sword>(25));
    inv.addItem(make_shared<Potion>(30));
    inv.addItem(make_shared<Bow>(15, 3));

    inv.showInventory();

    cout << "\n<-- Using items -->\n";
    inv.useItem(1, hero, &enemy);
    inv.useItem(2, hero);
    inv.useItem(3, hero, &boss);

    return 0;
}
