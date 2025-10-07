#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

void Loop()
{
    string answer;
    cout << "Write your command (generatePassword): ";
    cin >> answer;

    if (answer == "generatePassword")
    {
        int N;
        const int MAX_SIZE = 128;
        char str[MAX_SIZE];
        srand(time(0));

        do
        {
            system("cls");
            cout << "Enter the size of the password to generate (N > 5): ";
            cin >> N;
        } while (N <= 5 || N >= MAX_SIZE);

        const string chars =
            "abcdefghijklmnopqrstuvwxyz"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "0123456789"
            "!@#$%^&*()-_=+[]{};:,.<>?";

        for (int i = 0; i < N; ++i)
        {
            int index = rand() % chars.size();
            str[i] = chars[index];
        }

        str[N] = '\0';

        cout << "\nGenerated password: " << str << endl;
    }
    else
    {
        cout << "Error: unknown command.\n";
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Loop();
    return 0;
}
