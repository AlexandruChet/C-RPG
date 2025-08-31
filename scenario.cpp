#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Hero
{
public:
    string achievement;
    int hp = 100;
    int gold = 0;
};

Hero hero;

void dragon();
void tournament();
void conspiracy_against_the_king();

bool battle(string enemy, int enemyHP, int enemyAttack)
{
    cout << "\n⚔️ You face " << enemy << "!" << endl;
    while (hero.hp > 0 && enemyHP > 0)
    {
        int damageToEnemy = rand() % 20 + 5;
        int damageToHero = rand() % enemyAttack;

        enemyHP -= damageToEnemy;
        hero.hp -= damageToHero;

        cout << "You hit " << enemy << " for " << damageToEnemy << " dmg. "
             << enemy << " HP: " << max(0, enemyHP) << endl;
        cout << enemy << " hits you for " << damageToHero << " dmg. Your HP: " << max(0, hero.hp) << endl;

        if (enemyHP <= 0)
        {
            cout << "🎉 You defeated " << enemy << "!" << endl;
            return true;
        }
        if (hero.hp <= 0)
        {
            cout << "💀 You were killed by " << enemy << "." << endl;
            return false;
        }
    }
    return false;
}

void three_doors()
{
    char door;
    cout << "You have three doors. Which one will you open?" << endl;
    cout << "1 - Dragon's cave" << endl;
    cout << "2 - Tournament" << endl;
    cout << "3 - Conspiracy against the king" << endl;
    cin >> door;

    if (door == '1')
    {
        dragon();
    }
    else if (door == '2')
    {
        tournament();
    }
    else if (door == '3')
    {
        conspiracy_against_the_king();
    }
    else
    {
        cout << "There is no such door!" << endl;
    }
}

int main()
{
    srand(time(0));
    three_doors();

    cout << "\n=== The End ===" << endl;
    cout << "Your HP: " << hero.hp << endl;
    cout << "Your Gold: " << hero.gold << endl;
    if (!hero.achievement.empty())
    {
        cout << "Your achievement: " << hero.achievement << endl;
    }
    return 0;
}

void dragon()
{
    char choice;
    cout << "\n🐉 The dragon is looking at you, what will you do?" << endl;
    cout << "A - Cover yourself with a shield" << endl;
    cout << "B - Run away" << endl;
    cout << "C - Shoot him with a bow" << endl;
    cout << "D - Try to talk with him" << endl;
    cin >> choice;

    if (choice == 'A')
    {
        cout << "🔥 Your shield melts, and the dragon finishes you off." << endl;
        hero.hp = 0;
    }
    else if (choice == 'B')
    {
        if (battle("Dragon", 80, 20))
        {
            cout << "You survived the dragon fight!" << endl;
            hero.achievement = "Slayer of Dragons";
            hero.gold += 200;
        }
    }
    else if (choice == 'C')
    {
        cout << "Your arrow hits, but fire consumes you..." << endl;
        hero.hp = 0;
    }
    else if (choice == 'D')
    {
        cout << "You speak bravely to the dragon. Surprisingly, he listens!" << endl;
        cout << "Dragon offers you a choice:\n";
        cout << "E - Become his servant\nF - Make him your ally\n";
        cin >> choice;
        if (choice == 'E')
        {
            hero.achievement = "Dragon Servant";
            hero.gold += 50;
        }
        else if (choice == 'F')
        {
            hero.achievement = "Dragon Rider";
            hero.gold += 300;
        }
    }
}

void tournament()
{
    char choice;
    cout << "\n🏰 You are in the royal tournament!" << endl;
    cout << "Choose your strategy:" << endl;
    cout << "A - Fight with honor\nB - Fight dirty\nC - Bribe the judge\nD - Withdraw from the tournament\n";
    cin >> choice;

    if (choice == 'A')
    {
        if (battle("Knight", 60, 15))
        {
            cout << "🏆 You won with honor! The king rewards you." << endl;
            hero.achievement = "Champion of the Kingdom";
            hero.gold += 150;
        }
    }
    else if (choice == 'B')
    {
        cout << "You fight dirty!" << endl;
        if (battle("Knight", 50, 10))
        {
            cout << "You won, but the crowd boos you." << endl;
            hero.achievement = "Dishonorable Fighter";
            hero.gold += 50;
        }
    }
    else if (choice == 'C')
    {
        cout << "You bribed the judge with 30 gold..." << endl;
        if (hero.gold >= 30)
        {
            hero.gold -= 30;
            cout << "The judge declares you winner! (corruption wins)" << endl;
            hero.achievement = "Corrupt Champion";
        }
        else
        {
            cout << "But you had no gold. You were thrown out!" << endl;
        }
    }
    else if (choice == 'D')
    {
        cout << "You decide to withdraw. The crowd laughs at you, but you live." << endl;
        hero.achievement = "Coward Survivor";
    }
}

void conspiracy_against_the_king()
{
    char choice;
    cout << "\n👑 You overhear a conspiracy against the king!" << endl;
    cout << "What do you do?\n";
    cout << "A - Tell the king\nB - Join the conspirators\nC - Blackmail both sides\nD - Kill the conspirators yourself\n";
    cin >> choice;

    if (choice == 'A')
    {
        cout << "The king rewards you for your loyalty with 100 gold." << endl;
        hero.achievement = "Trusted Advisor";
        hero.gold += 100;
    }
    else if (choice == 'B')
    {
        cout << "You join the conspirators..." << endl;
        if (battle("Royal Guards", 70, 15))
        {
            cout << "The coup succeeds! You take power." << endl;
            hero.achievement = "Usurper King";
            hero.gold += 300;
        }
    }
    else if (choice == 'C')
    {
        cout << "You decide to blackmail both sides." << endl;
        hero.achievement = "Master Manipulator";
        hero.gold += 200;
    }
    else if (choice == 'D')
    {
        cout << "You attack the conspirators in the shadows!" << endl;
        if (battle("Conspirators", 50, 12))
        {
            cout << "You killed them all. The king never knew, but the realm is safe." << endl;
            hero.achievement = "Silent Protector";
            hero.gold += 150;
        }
    }
}
