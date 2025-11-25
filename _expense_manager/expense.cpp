#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>

using namespace std;

string get_date()
{
    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);
    tm *now_tm = localtime(&now_c);

    char buffer[20];
    sprintf(buffer, "%04d-%02d-%02d %02d:%02d",
            now_tm->tm_year + 1900,
            now_tm->tm_mon + 1,
            now_tm->tm_mday,
            now_tm->tm_hour,
            now_tm->tm_min);

    return string(buffer);
}

class manager
{
public:
    virtual void your_money() = 0;
    virtual void add_expense() = 0;
    virtual void show_all_expenses() = 0;
    virtual void show_total_amount() = 0;
    virtual void show_expenses_by_category() = 0;
    virtual void save_to_file() = 0;
    virtual void go_out() = 0;
};

class Expense
{
public:
    float amount;
    string category;
    string date;

    Expense(float a, const string &c, const string &d)
        : amount(a), category(c), date(d) {}
};

class PersonalManager : public manager
{
private:
    vector<Expense> expenses;

public:
    float balance = 0;

    void your_money() override
    {
        cout << "Please enter your current balance: ";
        cin >> balance;
    }

    void add_expense() override
    {
        vector<vector<string>> goods = {
            {"Bread", "2"},
            {"Milk", "3"},
            {"Apple", "1"},
            {"Cheese", "5"}};

        string item;
        cout << "Enter item name (or Exit to cancel): ";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, item);

        if (item == "Exit" || item == "exit")
        {
            cout << "Cancelled.\n";
            return;
        }

        bool found = false;
        float price = 0;

        for (auto &g : goods)
        {
            if (g[0] == item)
            {
                price = stof(g[1]);
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Item not found!\n";
            return;
        }

        if (balance < price)
        {
            cout << "Not enough money!\n";
            return;
        }

        balance -= price;
        expenses.push_back(Expense(price, item, get_date()));

        cout << "Expense added! Remaining balance: " << balance << endl;
    }

    void show_all_expenses() override
    {
        for (auto &e : expenses)
        {
            cout << e.category << " - " << e.amount
                 << " (" << e.date << ")\n";
        }
    }

    void show_total_amount() override
    {
        float total = 0;
        for (auto &e : expenses)
            total += e.amount;
        cout << "Total spent: " << total << endl;
    }

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
