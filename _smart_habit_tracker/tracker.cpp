#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

struct HabitItem
{
    string name;
    vector<bool> history;
};

class Habit
{
public:
    virtual void add_new_habit() = 0;
    virtual void remove_habit() = 0;
    virtual void edit_habit() = 0;
    virtual void mark_habit() = 0;
    virtual void view_all() = 0;
    virtual ~Habit() {}
};

class smart_habit : public Habit
{
private:
    vector<HabitItem> habits;

public:
    void add_new_habit() override
    {
        HabitItem h;
        cout << "Enter habit name: ";
        cin >> h.name;

        h.history = vector<bool>(7, false);

        habits.push_back(h);

        cout << "Habit added!\n";
    }

    void remove_habit() override
    {
        cout << "Enter habit name to remove: ";
        string target;
        cin >> target;

        auto it = remove_if(habits.begin(), habits.end(),
                            [&](const HabitItem &h)
                            { return h.name == target; });

        if (it != habits.end())
        {
            habits.erase(it, habits.end());
            cout << "Removed.\n";
        }
        else
            cout << "Not found.\n";
    }

    void edit_habit() override
    {
        cout << "Which habit to edit? ";
        string oldName;
        cin >> oldName;

        auto it = find_if(habits.begin(), habits.end(),
                          [&](const HabitItem &h)
                          { return h.name == oldName; });

        if (it == habits.end())
        {
            cout << "Not found.\n";
            return;
        }

        cout << "Enter new name: ";
        cin >> it->name;
        cout << "Updated!\n";
    }

    void mark_habit() override
    {
        cout << "Which habit to mark? ";
        string name;
        cin >> name;

        auto it = find_if(habits.begin(), habits.end(),
                          [&](const HabitItem &h)
                          { return h.name == name; });

        if (it == habits.end())
        {
            cout << "Not found.\n";
            return;
        }

        cout << "Was it done today? (1=yes, 0=no): ";
        bool done;
        cin >> done;

        it->history.insert(it->history.begin(), done);

        if (it->history.size() > 7)
            it->history.pop_back();

        cout << "Marked!\n";
    }

    void view_all() override
    {
        cout << "\n========== HABITS ==========\n";

        for (const auto &h : habits)
        {
            cout << "Habit: " << h.name << "\nHistory: ";

            for (bool d : h.history)
                cout << (d ? "✔ " : "✖ ");

            cout << "\n--------------------------\n";
        }
    }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    smart_habit app;

    app.add_new_habit();
    app.mark_habit();
    app.view_all();

    return 0;
}
