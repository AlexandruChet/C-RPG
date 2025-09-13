#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;
typedef unsigned int uint;

struct Item
{
    string text;
    double rate;
};

class Animal
{
protected:
    uint level;
    bool state;
    uint happiness;
    uint sadness;
    uint age;
    string name;
    vector<Item> items;

public:
    Animal(uint lv, bool st, uint hap, uint sad, uint ag, string nm)
        : level(lv), state(st), happiness(hap), sadness(sad), age(ag), name(nm) {}

    virtual void food() = 0;
    virtual void to_stroke() = 0;
    virtual void to_feed() = 0;
    virtual void update() = 0;
    virtual void wash() = 0;
    virtual void check() = 0;
    virtual void time() = 0;

    virtual ~Animal() = default;
};

class your_animal : public Animal
{
public:
    your_animal() : Animal(1, false, 0, 0, 0, "Dog")
    {
        items = {
            {"Meat", 15},
            {"Salad", 7},
            {"Broccoli", 5},
            {"Cabbage", 9},
            {"Feed", 20},
        };
    }

    void food() override
    {
        cout << "Available food:" << endl;
        for (const auto &i : items)
        {
            cout << i.text << " - " << i.rate << endl;
        }
    }

    void to_stroke() override
    {
        happiness += 20;
        cout << name << " is happy! Happiness = " << happiness << endl;
    }

    void to_feed() override
    {
        double amount;
        string from_currency;

        cout << "Enter food name: ";
        cin >> from_currency;
        cout << "Enter amount: ";
        cin >> amount;

        double from_rate = 0;
        for (const auto &i : items)
        {
            if (i.text == from_currency)
            {
                from_rate = i.rate;
                happiness += amount * from_rate;
                break;
            }
        }

        if (from_rate == 0)
        {
            cout << "Error: unknown food!" << endl;
        }
        else
        {
            cout << name << " ate " << from_currency
                 << " and got +" << (amount * from_rate)
                 << " happiness." << endl;
        }
    }

    void update() override
    {
        if (happiness >= 100)
        {
            cout << "Level 5" << endl;
            level = 5;
        }
        else if (happiness >= 75)
        {
            cout << "Level 4" << endl;
            level = 4;
        }
        else if (happiness >= 50)
        {
            cout << "Level 3" << endl;
            level = 3;
        }
        else if (happiness >= 20)
        {
            cout << "Level 2" << endl;
            level = 2;
        }
        else
        {
            cout << "Level 1" << endl;
            level = 1;
        }
    }

    void wash() override
    {
        happiness += 15;
        cout << name << " feels fresh! Happiness = " << happiness << endl;
    }

    void check() override
    {
        string state_animal;
        if (happiness < 20)
        {
            state_animal = "The animal is very sad.";
        }
        else if (happiness < 50)
        {
            state_animal = "So far everything is fine.";
        }
        else if (happiness < 75)
        {
            state_animal = "She is cheerful.";
        }
        else
        {
            state_animal = "Everything is fine.";
        }

        cout << "Your pet has happiness = " << happiness
             << ". " << state_animal << endl;
    }

    void time() override
    {
        thread([this]()
               {
        while (happiness > 0) {
            this_thread::sleep_for(chrono::seconds(30));
            happiness--;
        } })
            .detach();
    }
};

int game_loop()
{
    your_animal dog;
    uint choice;

    while (true)
    {
        cout << "\n1. Show food\n2. Feed\n3. Stroke\n4. Wash\n5. Update level\n6. Check state\n7. Exit\n";
        cout << "Choose action: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            dog.food();
            break;
        case 2:
            dog.to_feed();
            break;
        case 3:
            dog.to_stroke();
            break;
        case 4:
            dog.wash();
            break;
        case 5:
            dog.update();
            break;
        case 6:
            dog.check();
            break;
        case 7:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}

int main()
{
    return game_loop();
}
