#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void swapValues(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T maxValue(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T, typename U>
class Pair
{
    T first;
    U second;

public:
    Pair(T f, U s) : first(f), second(s) {}

    T getFirst() { return first; }
    U getSecond() { return second; }

    void print()
    {
        cout << "(" << first << ", " << second << ")" << endl;
    }
};

template <typename T, int SIZE>
class Array
{
    T data[SIZE];

public:
    Array()
    {
        for (int i = 0; i < SIZE; i++)
            data[i] = T();
    }

    T &operator[](int index) { return data[index]; }
    int size() const { return SIZE; }

    void print()
    {
        for (int i = 0; i < SIZE; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};

template <>
class Pair<string, string>
{
    string first;
    string second;

public:
    Pair(string f, string s) : first(f), second(s) {}

    void print()
    {
        cout << "[Specialized Pair]: " << first << " & " << second << endl;
    }
};

template <typename... Args>
void printAll(Args... args)
{
    (cout << ... << args) << endl;
}

template <typename T>
typename enable_if<is_integral<T>::value, T>::type
square(T x)
{
    return x * x;
}

int main()
{
    cout << "=== Function templates ===" << endl;
    int a = 5, b = 10;
    cout << "Before swap: a=" << a << ", b=" << b << endl;
    swapValues(a, b);
    cout << "After swap:  a=" << a << ", b=" << b << endl;

    cout << "maxValue(7, 3) = " << maxValue(7, 3) << endl;
    cout << "maxValue(2.5, 9.1) = " << maxValue(2.5, 9.1) << endl;

    cout << "\n=== Class template Pair ===" << endl;
    Pair<int, string> p1(1, "One");
    Pair<double, char> p2(3.14, 'A');
    Pair<string, string> p3("Hello", "World");

    p1.print();
    p2.print();
    p3.print();

    cout << "\n=== Template Array ===" << endl;
    Array<int, 5> arr;
    for (int i = 0; i < arr.size(); i++)
        arr[i] = i * 10;
    arr.print();

    Array<string, 3> strArr;
    strArr[0] = "Alpha";
    strArr[1] = "Beta";
    strArr[2] = "Gamma";
    strArr.print();

    cout << "\n=== Variadic templates ===" << endl;
    printAll("Values: ", 1, ", ", 2.5, ", ", 'X', ", ", string("C++"));

    cout << "\n=== Template constraints (enable_if) ===" << endl;
    cout << "square(5) = " << square(5) << endl;

    cout << "\n=== Vector + template usage ===" << endl;
    vector<Pair<int, string>> vec;
    vec.push_back(Pair<int, string>(1, "One"));
    vec.push_back(Pair<int, string>(2, "Two"));
    vec.push_back(Pair<int, string>(3, "Three"));

    for (auto &item : vec)
        item.print();

    cout << "\n=== Sorting with templates ===" << endl;
    vector<int> nums = {5, 2, 8, 1, 3};
    sort(nums.begin(), nums.end());
    for (int n : nums)
        cout << n << " ";
    cout << endl;

    return 0;
}
