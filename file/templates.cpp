#include <iostream>
using namespace std;

template <typename T, typename U>
class Pair
{
    T first;
    U second;

public:
    Pair(T f, U s) : first(f), second(s) {}
    void print()
    {
        cout << first << ", " << second << endl;
    }
};

int main()
{
    Pair<int, string> p1(1, "Hello");
    Pair<double, char> p2(3.14, 'A');

    p1.print();
    p2.print();
}
