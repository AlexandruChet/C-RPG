#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cout << "n = ? ";
    cin >> n;

    if (n <= 0)
    {
        cout << "The number of lines should be > 0\n";
        return 1;
    }

    cin.ignore();

    string* strings = new string[n];

    for (int i = 0; i < n; i++)
        getline(cin, strings[i]);

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ": " << strings[i] << endl;
        cout << "Total number of characters: "
             << strings[i].length() << endl;
    }

    int maxIndex = 0;
    for (int i = 1; i < n; i++)
        if (strings[i].length() > strings[maxIndex].length())
            maxIndex = i;

    cout << "The longest line is: " << strings[maxIndex] << endl;

    delete[] strings;
    return 0;
}
