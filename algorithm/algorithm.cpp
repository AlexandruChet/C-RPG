#include <bits/stdc++.h>
using namespace std;

void guessNumber(int target, int minVal = 1, int maxVal = 1000)
{
    int attempts = 0;

    while (minVal <= maxVal)
    {
        int guess = (minVal + maxVal) / 2;
        attempts++;
        cout << "Computer guesses: " << guess << "\n";

        if (guess == target)
        {
            cout << "Computer found the number " << target
                 << " in " << attempts << " attempts!\n";
            return;
        }
        else if (guess > target)
        {
            cout << "Too high! Trying lower...\n";
            maxVal = guess - 1;
        }
        else
        {
            cout << "Too low! Trying higher...\n";
            minVal = guess + 1;
        }
    }

    cout << "Number not found!\n";
}

int main()
{
    guessNumber(456);
    return 0;
}
