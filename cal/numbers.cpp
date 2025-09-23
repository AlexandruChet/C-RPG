#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    srand(time(0));

    for (int x = 0; x < 15; x++)
    {
        int num = 1 + (rand() % 6);
        cout << num << " ";

        if (num % 2 == 0)
        {
            cout << "even number";
        }
        else
        {
            cout << "odd number";
        }

        cout << endl;
    }

    return 0;
}
