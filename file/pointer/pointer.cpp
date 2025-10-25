#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

string getName()
{
    string name; // ~24 bytes (string structure without text in heap)
    cout << "Write your name: ";
    cin >> name;

    string *namePointer = &name; // 8 bytes (pointer to string)
    return *namePointer;         // return a copy of the string
}

void pointerValue()
{
    int x = 10;  // 4 bytes (integer)
    int *y = &x; // 8 bytes (pointer to int)
    *y = 5;      // changes the value of x via pointer
    cout << "x = " << x << endl;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8); // set UTF-8 in console

    int num = 15;    // 4 bytes (integer)
    int *ptr = &num; // 8 bytes (pointer to int)

    cout << "num = " << num << endl;
    cout << "*ptr = " << *ptr << endl;

    int arr[3] = {10, 20, 30}; // 3 * 4 = 12 bytes (array of three ints)
    int *p = arr;              // 8 bytes (pointer to first element of array)

    cout << "arr[0] = " << *p << endl;
    cout << "arr[1] = " << *(p + 1) << endl;
    cout << "arr[2] = " << *(p + 2) << endl;

    cout << "Your name: " << getName() << endl; // getName() returns string (~24 bytes + text in heap)

    int numbers[10][10] = {// 10 * 10 * 4 = 400 bytes (2D int array)
                           {3, 2},
                           {5, 10},
                           {9, 10}};

    int (*numbersPointer)[10] = numbers; // 8 bytes (pointer to array of 10 ints)
    cout << "numbers[0][0] = " << numbersPointer[0][0] << endl;

    pointerValue(); // creates local x (4 bytes) and y (8 bytes)

    return 0;
}