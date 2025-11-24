#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>

using namespace std;

void show_date()
{
    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);
    tm *now_tm = localtime(&now_c);

    cout << "Current date: "
         << now_tm->tm_year + 1900 << "-"
         << now_tm->tm_mon + 1 << "-"
         << now_tm->tm_mday << " "
         << now_tm->tm_hour << ":"
         << now_tm->tm_min << endl;
}

class manager
{
public:
    virtual void add_expense() = 0;
    virtual void show_all_expenses() = 0;
    virtual void show_total_amount() = 0;
    virtual void show_expenses_by_category() = 0;
    virtual void save_to_file() = 0;
    virtual void go_out() = 0;
};

class PersonalManager : public manager
{
private:
    vector<float> expenses;

public:
    void add_expense() override {}

    void show_all_expenses() override {}

    void show_total_amount() override {}

    void show_expenses_by_category() override {}

    void save_to_file() override {}

    void go_out() override {}
};

int main()
{
    PersonalManager pm;

    int choice;
    do
    {
        cout << "\n1. Add expense\n2. Show all\n3. Total\n0. Exit\n> ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            pm.add_expense();
            break;
        case 2:
            pm.show_all_expenses();
            break;
        case 3:
            pm.show_total_amount();
            break;
        }

    } while (choice != 0);

    return 0;
}
