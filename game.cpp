#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Item
{
    string text;
    double rate;
};

double convert_to_usd(double amount, double rate)
{
    return amount / rate;
}

class Animal
{
private:
    int level;
    bool state;
    int happiness;
    int sadness;
    int age;
    string name;
vector<Item>

    public : Animal(int lv, bool st, int hap, int sad, int ag, string nm)
    : level(lv), state(st), happiness(hap), sadness(sad), age(ag), name(nm)
    {
        items = {
            {"Meat", 15},
            {"Salad", 7},
            {"Broccoli", 5},
            {"Cabbage", 9},
            {"Feed", 20},
        };
    }

    virtual void food()
    {
        cout << "Available food:" << endl;
        for (const auto &i : items)
        {
            cout << i.text << " - " << i.rate << endl;
        }
    }

    virtual void to_stroke()
    {
        happiness += 20;
        cout << name << " is happy! Happiness = " << happiness << endl;
    }

    virtual void to_feed()
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
                happiness += amount;
                break;
            }
        }

        if (from_rate == 0)
        {
            cout << "Error: unknown food!" << endl;
        }
        else
        {
            cout << name << " ate " << from_currency << " and got +" << amount << " happiness." << endl;
        }
    }

    virtual void update()
    {
        if (happiness >= 0)
        {
            cout << "Level 1" << endl;
            level = 1;
        }

        if (happiness >= 20)
        {
            cout << "Level 2" << endl;
            level = 2;
        }
        else if (happiness >= 50)
        {
            cout << "Level 3" << endl;
            level = 3;
        }
        else if (happiness >= 75)
        {
            cout << "Level 4" << endl;
            level = 4;
        }
        else if (happiness >= 100)
        {
            cout << "Level 5" << endl;
            level = 5;
        }
    }

    virtual void wash()
    {
        happiness += 15;
    }
};

class your_animal : public Animal {
    public:
        your_animal() : Animal(1, false, 0, 0, 0, "Dog") {}
}

int game_loop()
{
    return 0;
}

int main()
{
    return game_loop();
}
