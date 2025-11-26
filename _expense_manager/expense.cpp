#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>
#include <fstream>
#include <limits>

using namespace std;

string get_date()
{
    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);
    tm* now_tm = localtime(&now_c);

    char buffer[20];
    sprintf(
        buffer,
        "%04d-%02d-%02d %02d:%02d",
        now_tm->tm_year + 1900,
        now_tm->tm_mon + 1,
        now_tm->tm_mday,
        now_tm->tm_hour,
        now_tm->tm_min
    );

    return string(buffer);
}

class Expense
{
public:
    float amount;
    string category;
    string date;

    Expense(float a, const string& c, const string& d)
        : amount(a), category(c), date(d) {}

    Expense()
        : amount(0), category(""), date("") {}
};

class PersonalManager
{
private:
    vector<Expense> expenses;

public:
    float balance = 0;

    vector<pair<string, float>> goods =
    {
        { "Bread", 2 },
        { "Milk", 3 },
        { "Apple", 1 },
        { "Cheese", 5 }
    };

    void your_money()
    {
        cout << "Please enter your current balance: ";
        cin >> balance;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void add_expense()
    {
        cout << "Enter item name (or Exit): ";

        string item;
        getline(cin, item);

        if (item == "Exit" || item == "exit")
        {
            return;
        }

        bool found = false;
        float price = 0;

        for (auto& g : goods)
        {
            if (g.first == item)
            {
                found = true;
                price = g.second;
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

    void show_all_expenses()
    {
        if (expenses.empty())
        {
            cout << "No expenses.\n";
            return;
        }

        for (auto& e : expenses)
        {
            cout << e.category << " - " << e.amount
                 << " (" << e.date << ")\n";
        }
    }

    void show_total_amount()
    {
        float total = 0;

        for (auto& e : expenses)
        {
            total += e.amount;
        }

        cout << "Total spent: " << total << endl;
    }

    void save_to_file()
    {
        ofstream file("expenses.txt");

        if (!file.is_open())
        {
            cout << "Error saving data!\n";
            return;
        }

        file << "BALANCE: " << balance << "\n";

        for (auto& e : expenses)
        {
            file << e.category << "|"
                 << e.amount << "|"
                 << e.date << "\n";
        }

        file.close();
        cout << "Saved to expenses.txt\n";
    }

    void load_from_file()
    {
        ifstream file("expenses.txt");

        if (!file.is_open())
        {
            cout << "No saved data found.\n";
            return;
        }

        expenses.clear();

        string line;
        getline(file, line);

        if (line.rfind("BALANCE:", 0) == 0)
        {
            balance = stof(line.substr(9));
        }
        else
        {
            cout << "File has invalid format.\n";
            return;
        }

        while (getline(file, line))
        {
            if (line.empty())
            {
                continue;
            }

            size_t p1 = line.find("|");
            size_t p2 = line.find("|", p1 + 1);

            string category = line.substr(0, p1);
            float amount = stof(line.substr(p1 + 1, p2 - p1 - 1));
            string date = line.substr(p2 + 1);

            expenses.emplace_back(amount, category, date);
        }

        cout << "Data loaded.\n";
    }
};

int main()
{
    PersonalManager pm;

    pm.load_from_file();

    if (pm.balance == 0)
    {
        pm.your_money();
    }

    int choice;

    do
    {
        cout << "\n1. Add expense\n"
             << "2. Show all\n"
             << "3. Total\n"
             << "4. Save\n"
             << "0. Exit\n> ";

        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

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

            case 4:
                pm.save_to_file();
                break;
        }

    } while (choice != 0);

    pm.save_to_file();

    return 0;
}
