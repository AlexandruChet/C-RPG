#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <random>
#include <chrono>
#include <thread>
#include <atomic>

using namespace std;

void estimateTime(string password);

int main()
{
    int score = 0;
    string password;
    vector<string> warnings;

    cout << "Enter your password: ";
    cin >> password;

    cout << "\nChecking your password...\n";

    if (password.length() >= 12)
    {
        cout << "✔ Password length is OK\n";
        score += 25;
    }
    else
    {
        cout << "✘ Password is too short (minimum 12 characters required)\n";
        score -= 10;
    }

    bool hasUpper = false;
    for (char c : password)
        if (isupper(c))
            hasUpper = true;

    if (hasUpper)
        score += 20;
    else
        warnings.push_back("No uppercase letters (A-Z)");

    bool hasLower = false;
    for (char c : password)
        if (islower(c))
            hasLower = true;

    if (hasLower)
        score += 20;
    else
        warnings.push_back("No lowercase letters (a-z)");

    bool hasDigit = false;
    for (char c : password)
        if (isdigit(c))
            hasDigit = true;

    if (hasDigit)
        score += 20;
    else
        warnings.push_back("No digits (0-9)");

    string specials = "!@#$%^&*()-_=+[]{};:,.<>/?|";
    bool hasSpecial = false;
    for (char c : password)
        if (specials.find(c) != string::npos)
            hasSpecial = true;

    if (hasSpecial)
        score += 20;
    else
        warnings.push_back("No special characters (e.g. !, @, %, $)");

    cout << "\n--- RESULTS ---\n";
    cout << "Password score: " << score << "/100\n";

    if (!warnings.empty())
    {
        cout << "\nWarnings:\n";
        for (auto &w : warnings)
            cout << " - " << w << endl;
    }

    estimateTime(password);

    return 0;
}

void estimateTime(string password)
{
    const string symbols =
        "QqWwEeRrTtYyUuIiOoPpAaSsDdFfGgHhJjKkLlZzXxCcVvBbNnMm?!@#$%^&*()1234567890_+-=|";

    random_device rd;
    mt19937_64 rng(rd());

    auto generatePassword = [&](int length)
    {
        string pass;
        uniform_int_distribution<> dist(0, symbols.size() - 1);
        for (int i = 0; i < length; i++)
            pass += symbols[dist(rng)];
        return pass;
    };

    int length = password.size();
    string basicPas = password;

    cout << "\n--- BRUTE FORCE ESTIMATION ---\n";
    cout << "Target: " << basicPas << endl;

    string attempt;
    long long tries = 0;
    const long long maxAttempts = 5000000000000000000LL;
    const int batchSize = 2000;

    auto startTime = chrono::steady_clock::now();
    bool found = false;

    atomic<bool> running(true);

    thread statsThread([&]()
                       {
        while (running)
        {
            this_thread::sleep_for(chrono::seconds(1));
            auto now = chrono::steady_clock::now();
            double elapsed = chrono::duration<double>(now - startTime).count();

            long long speed = static_cast<long long>(tries / max(0.000001, elapsed));

            cout << "Elapsed: " << elapsed << "s "
                 << "| Attempts: " << tries
                 << " | Speed: " << speed << " tries/s"
                 << endl;
        } });

    while (tries < maxAttempts)
    {
        for (int i = 0; i < batchSize; i++)
        {
            attempt = generatePassword(length);
            tries++;

            if (attempt == basicPas)
            {
                found = true;
                break;
            }
        }

        if (found)
            break;
    }

    running = false;
    statsThread.join();

    auto endTime = chrono::steady_clock::now();
    double totalSec = chrono::duration<double>(endTime - startTime).count();

    cout << "\n--- RESULT ---\n";

    if (found)
    {
        cout << "Password found: " << attempt << endl;
        cout << "Attempts: " << tries << endl;
        cout << "Time: " << totalSec << "s\n";
        cout << "Avg speed: " << tries / totalSec << " tries/s\n";
    }
    else
    {
        cout << "Stopped at maxAttempts. Last attempt: " << attempt << endl;
    }
}
