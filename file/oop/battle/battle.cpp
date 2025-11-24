#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <windows.h>

using namespace std;

class Character // this is main class
{
protected:
    float strength;
    float speed;
    string name;
    float health;
    float defenseValue;
    bool dodging = false;

public:
    Character(float str, float sp, string n, float heal, float def)
        : strength(str), speed(sp), name(n), health(heal), defenseValue(def) {} // my constructor

    virtual void attack(Character &target) = 0;
    virtual void defense() = 0;
    virtual void recovery() = 0;
    virtual bool miss() = 0;
    virtual void random(Character &target) = 0; // my main virtual func.

    void takeDamage(float dmg) { health -= dmg; }
    void addDefense(float value) { defenseValue += value; }
    void addStrength(float value) { strength += value; }
    void heal(float value) { health += value; } // this is help to main functions

    float getHealth() const { return health; } // this is getter for health

    void setDodging(bool value) { dodging = value; }
    bool isDodging() const { return dodging; } // this is for miss
};

class Hero : public Character
{
private:
    int mana;

public:
    Hero() : Character(50, 100, "Hero", 100, 30), mana(100) {} // constructor

    void attack(Character &target) override // attack func Hero
    {
        if (target.isDodging())
        {
            cout << "Hero attacks, but enemy dodges!\n";
            target.setDodging(false);
            return;
        }

        if (miss())
        {
            cout << "Hero missed!\n";
            mana -= 10;
            return;
        }

        float dmg = (rand() % 100 < 80) ? strength : strength * 1.5;
        target.takeDamage(dmg);
        cout << "Hero deals " << dmg << " damage!\n";
    }

    void defense() override // defense func
    {
        addDefense(30);
    }

    void recovery() override // recovery
    {
        heal(30);
    }

    bool miss() override
    {
        return (rand() % 100) >= 80;
    }

    void useMiss() // useMiss Dodging func
    {
        if (mana < 20)
        {
            cout << "Not enough mana to dodge!\n";
            return;
        }
        mana -= 10;
        dodging = true; // dodge func
        cout << "Hero prepares to dodge! (Mana: " << mana << ")\n";
    }

    void random(Character &target) override // random func
    {
        vector<string> perks = {"Defense", "Attack", "Health", "Mana", "", ""}; // perks
        int index = rand() % perks.size();
        string perk = perks[index];

        if (perk == "Defense") // verification my enemy logic
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
    Enemy() : Character(35, 60, "Enemy", 300, 10), mana(50) {} // Enemys constructor

    void attack(Character &target) override // Enemys attack func
    {
        if (target.isDodging())
        {
            cout << "Enemy attacks, but hero dodges!\n";
            target.setDodging(false);
            return;
        }

        if (miss())
        {
            cout << "Enemy missed!\n";
            return;
        }

        float dmg = (rand() % 100 < 80) ? strength : strength * 1.1;
        target.takeDamage(dmg);
        cout << "Enemy deals " << dmg << " damage!\n";
    }

    void useMiss()
    {
        if (mana < 10)
            return;
        mana -= 10;
        dodging = true;
        cout << "Enemy prepares to dodge!\n";
    }

    void
    defense() override
    {
        addDefense(10);
    }

    void recovery() override
    {
        heal(15);
    }

    bool miss() override
    {
        return (rand() % 100) >= 80;
    }

    void random(Character &target) override
    {
        int random_chance = rand() % 4 + 1;
        if (random_chance == 1)
        {
            attack(target);
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠄⢤⣠⢷⣝⢦⠀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠒⣲⣦⣺⣳⣤⡿⠛⠃⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠉⠢⣣⣁⠀⣀⠙⢧⠀⠀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⡎⠑⢤⡼⡩⡪⠷⠀⠀⡇⠀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⣶⡞⢯⣠⡻⠼⡇⠀⠀⠀⡇⠀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡷⢌⠻⣶⡟⡄⠈⠁⠀⠀⠐⢣⡀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⡴⣷⣿⡗⠀⣡⠊⠻⠋⠒⢄⠀⠀⢀⠔⠙⢦⡀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⡠⠊⠁⢺⣿⢇⠜⠁⠀⠀⠀⠀⣠⠗⠊⠀⠀⣠⡺⠆⠀\n";
            cout << "⠀⠀⠀⠀⣠⣾⡗⠀⠀⢸⡿⠋⠀⠀⠀⠀⠀⠀⠻⣆⠛⣠⣞⢕⢽⣆⠀\n";
            cout << "⠀⠀⠀⣴⣿⣿⡇⠀⢀⠞⠁⠀⠀⠀⠀⠀⠀⠀⢐⡯⡪⡫⡢⣑⣕⢕⠀\n";
            cout << "⠀⠀⣼⣿⣿⣿⠇⡰⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢮⡺⣾⣮⡪⡳⠀\n";
            cout << "⢀⣼⣿⣿⣿⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠺⣷⣝⢮⠀\n";
            cout << "⠾⠿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠪⣻⡇\n";
        }
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
    srand(static_cast<unsigned int>(time(0)));
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
            cout << "------------------------\n";
            cout << "殪幢緻Iii爰曷樔黎㌢´　　｀ⅷ\n";
            cout << "艇艀裲f睚鳫巓襴骸　　　　贒憊\n";
            cout << "殪幢緻I翰儂樔黎夢'”　 　 ,ｨ傾\n";
            cout << "盥皋袍i耘蚌紕偸′　　　 雫寬I\n";
            cout << "悗f篝嚠篩i縒縡齢　　 　 Ⅷ辨f\n";
            cout << "輯駲f迯瓲i軌帶′　　　　　`守I厖孩\n";
            cout << "幢儂儼巓襴緲′　 　 　 　 　 `守枢i磬廛\n";
            cout << "嚠篩I縒縡夢'´　　　 　 　 　 　 　 `守峽f\n";
            cout << "蚌紕襴緲′　　　　　　　　　　　　　‘守畝\n";
            cout << "f瓲軌揄′　　　　　　　　　　　　　,gf毯綴\n";
            cout << "鳫襴鑿　　　　　　　　　　 　 　 奪寔f厦\n";
            cout << "絨緲′　　　　　　 　 　 　 　　　　 　 ”'罨悳\n";
            cout << "巓緲′　　　　　　 　 　 　 　 　 　 綴〟 ”'罨椁\n";
            cout << "巓登嶮 薤篝㎜㎜ g　 　 緲　 　 甯體i爺綴｡, ”'罨琥\n";
            cout << "I軌襴暹 甯幗緲fi'　　 緲',纜　　贒i綟碕碚爺綴｡ ”'罨皴\n";
            cout << "巓襴驫 霤I緲緲　　 纜穐　　甯絛跨飩i髢綴馳爺綴｡`'等誄\n";
            cout << "-------------------------------------------------------------------------------------------------------\n";
        }
        else if (command == 'B')
        {
            hero.defense();
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣤⣤⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⠿⠿⠿⣿⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⡿⠋⠀⠀⠀⠀⠀⠙⢿⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⡟⠀⠀⠀⣀⣀⠀⠀⠀⠈⢿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣇⠀⣠⣾⣿⣿⣷⣄⠀⣀⣸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣶⣿⣿⣿⣿⣿⣿⣶⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⡿⢿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⢿⣿⣿⣧⣸⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠛⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
        }
        else if (command == 'C')
        {
            hero.recovery();
            cout << "⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀\n";
            cout << "⢀⣀⣀⣀⣀⣀⣀⣿⣿⣿⣿⣿⣿⣀⣀⣀⣀⣀⣀⡀\n";
            cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n";
            cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n";
            cout << "⢀⣀⣀⣀⣀⣀⣀⣿⣿⣿⣿⣿⣿⣀⣀⣀⣀⣀⣀⡀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀\n";
        }
        else if (command == 'D')
        {
            hero.useMiss();
            cout << "＜￣｀ヽ、　　　　　　　／￣＞\n";
            cout << "　ゝ、　　＼　／⌒ヽ,ノ 　/´\n";
            cout << "　　　ゝ、　`（ ( ͡° ͜ʖ ͡°) ／\n";
            cout << "　　 　　>　 　 　,ノ\n";
            cout << "　　　　　∠_,,,/´\n";
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
    SetConsoleOutputCP(CP_UTF8);
    game_play();
    return 0;
}
