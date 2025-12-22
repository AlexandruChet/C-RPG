#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cout << "n = ?" << " ";
    cin >> n;

    string *strings = new string[n];
    getline(cin, strings[0]);

    for (int i = 0; i < n; i++) 
        getline(cin, strings[i]);

    for (int i; i < n; i++)
        cout << strings[i] << endl;

    delete[] strings;

    return 0;
}