#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int number_of_assessments;
    double sum = 0, grade;

    cout << "Write how many grades you have: ";
    cin >> number_of_assessments;

    if (number_of_assessments <= 0)
    {
        cout << "Number of grades must be greater than 0." << endl;
        return 0;
    }

    for (int i = 0; i < number_of_assessments; i++)
    {
        do
        {
            cout << "Enter your rating " << i + 1 << " (1 - 6): ";
            cin >> grade;
        } while (grade < 1 || grade > 6);
        sum += grade;
    }

    double avg = sum / number_of_assessments;
    avg = round(avg * 100) / 100;
    cout << "Your average score is " << avg << endl;

    if (avg <= 1.5)
        cout << "Excellent (German grading system)" << endl;
    else if (avg <= 3.0)
        cout << "Good (German grading system)" << endl;
    else if (avg <= 4.0)
        cout << "Average (German grading system)" << endl;
    else
        cout << "Bad" << endl;

    return 0;
}
