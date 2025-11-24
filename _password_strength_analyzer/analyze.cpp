#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int score = 0;
    string password;
    vector<string> warnings;

    cout << "Please write your password: ";
    cin >> password;

    cout << "Checking your password...\n";

    if (password.length() >= 12)
    {
        cout << "Your password length is OK\n";
        score += 25;
    }

    else
    {
        cout << "Your password is too short, needs at least 12 characters\n";
        score -= 10;
    }

    bool hasUpper = false;
    for (char e : password)
        if (isupper(e))
            hasUpper = true;

    if (hasUpper)
        score += 20;
    else
        warnings.push_back("No uppercase letters (A-Z)");

    cout << "Your score: " << score << "/100\n";
    if (!warnings.empty())
    {
        cout << "Warnings:\n";
        for (auto &w : warnings)
            cout << " - " << w << endl;
    }

    return 0;
}
