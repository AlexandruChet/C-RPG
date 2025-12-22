#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int number_of_assessments;
    double sum = 0, grade;

    cout << "Write how many grades you have: ";
    cin >> number_of_assessments;

    if (grade < 1 || grade > 6)
        cout << "Invalid input. Please enter a number from 1 to 6.\n";

    int count[6] = {0};

    for (int i = 0; i < number_of_assessments; i++)
    {
        do
        {
            cout << "Enter your rating " << i + 1 << " (1 - 6): ";
            cin >> grade;
        } while (grade < 1 || grade > 6);
        sum += grade;
        count[(int)grade - 1]++;
    }

    cout << "\nGrade statistics:\n";
    for (int i = 0; i < 6; i++)
    {
        cout << "Grade " << i + 1 << ": " << count[i] << " times\n";
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
