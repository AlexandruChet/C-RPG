#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double first_num, second_num; 
    char op; 

    cout << "Write first number: ";
    cin >> first_num;

    cout << "Write operator (+, -, *, /, ^ for power, s for square root): ";
    cin >> op;

    if (op != 's') {
        cout << "Write second number: ";
        cin >> second_num;
    }

    switch (op) {
        case '+':
            cout << "Result: " << first_num + second_num << endl;
            break;
        case '-':
            cout << "Result: " << first_num - second_num << endl;
            break;
        case '*':
            cout << "Result: " << first_num * second_num << endl;
            break;
        case '/':
            if (second_num == 0) {
                cout << "Error: division by zero!" << endl;
            } else {
                cout << "Result: " << first_num / second_num << endl;
            }
            break;
        case '^':
            cout << "Result: " << pow(first_num, second_num) << endl;
            break;
        case 's':
            if (first_num < 0) {
                cout << "Error: negative number under sqrt!" << endl;
            } else {
                cout << "Result: " << sqrt(first_num) << endl;
            }
            break;
        default:
            cout << "Unknown operator!" << endl;
    }

    return 0;
}