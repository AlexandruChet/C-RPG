#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));
    int playerHP = 100;
    int enemyHP = 50;

    std::cout << "The battle begins!\n";

    while (playerHP > 0 && enemyHP > 0)
    {
        int damage = rand() % 20 + 1;
        enemyHP -= damage;
        std::cout << "You have dealt " << damage << " damage to the enemy. Enemy health: " << enemyHP << "\n";

        if (enemyHP <= 0)
        {
            std::cout << "You have won!\n";
            break;
        }

        int enemyDamage = rand() % 15 + 1;
        playerHP -= enemyDamage;
        std::cout << "Enemy is attacking! Your health is: " << playerHP << "\n";

        if (playerHP <= 0)
        {
            std::cout << "You lost!\n";
        }
    }

    return 0;
}