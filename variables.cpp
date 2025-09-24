#include <iostream>

using namespace std;

int main()
{
    cout << "bool: " << sizeof(bool) << " byte(s)\n";
    cout << "char: " << sizeof(char) << " byte(s)\n";
    cout << "short: " << sizeof(short) << " byte(s)\n";
    cout << "int: " << sizeof(int) << " byte(s)\n";
    cout << "long: " << sizeof(long) << " byte(s)\n";
    cout << "long long: " << sizeof(long long) << " byte(s)\n";
    cout << "float: " << sizeof(float) << " byte(s)\n";
    cout << "double: " << sizeof(double) << " byte(s)\n";
    cout << "long double: " << sizeof(long double) << " byte(s)\n";

    return 0;
}