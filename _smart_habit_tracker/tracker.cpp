#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Habit
{
protected:
    vector<string> habit;
    vector<string> time;

public:
    Habit(vector<string> hab, vector<string> tm) : habit(hab), time(tm) {}

    virtual void add_new_habit() = 0;
    virtual void break_habit() = 0;
    virtual void edit_habit() = 0;
    virtual void view_list_of_all_habits() = 0;

    virtual ~Habit() {}
};

class smart_habit : public Habit
{
public:
    smart_habit(vector<string> habit, vector<string> time)
        : Habit(habit, time) {}

    void add_new_habit() override
    {
        string hab;
        cout << "Please write your habit: ";
        cin >> hab;
        habit.push_back(hab);

        string time_hab;
        cout << "How much time did you spend today? ";
        cin >> time_hab;
        time.push_back(time_hab);
    }

    void break_habit() override
    {
        cout << "Your habits: ";
        for (const auto &e : habit)
            cout << e << " ";
        cout << endl;

        cout << "Which habit do you want to remove? ";
        string answer;
        cin >> answer;

        auto it = find(habit.begin(), habit.end(), answer);
        if (it != habit.end())
        {
            habit.erase(it);
            cout << "Habit '" << answer << "' deleted.\n";
        }
        else
        {
            cout << "Habit '" << answer << "' not found.\n";
        }
    }

    void edit_habit() override
    {
        cout << "Your habits: ";
        for (const auto &e : habit)
            cout << e << " ";
        cout << endl;

        string oldWord, newWord;

        cout << "Which habit do you want to edit? ";
        cin >> oldWord;
        cout << "Write the new habit: ";
        cin >> newWord;

        auto it = find(habit.begin(), habit.end(), oldWord);

        if (it != habit.end())
        {
            *it = newWord;
            cout << "Habit updated.\n";
        }
        else
        {
            cout << "Habit not found.\n";
        }
    }

    void view_list_of_all_habits() override
    {
        cout << "\nHABITS:\n";
        for (const auto &e : habit)
            cout << e << " ";
        cout << "\nTIME:\n";
        for (const auto &e : time)
            cout << e << " ";
        cout << endl;
    }
};

int main()
{
    smart_habit app({}, {});
    app.add_new_habit();
    app.view_list_of_all_habits();

    return 0;
}
