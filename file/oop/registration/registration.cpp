#include <iostream>
#include <string>
#include <functional>
#include <windows.h>

using namespace std;

class Functional
{
protected:
    string name;
    int password;
    int login;

public:
    Functional(string name, int password, int login)
        : name(name), password(password), login(login) {}

    virtual string getName() { return name; }
    virtual int getPassword() { return password; }
    virtual int getLogin() { return login; }

    virtual void cypherName() = 0;
    virtual void cypherPassword() = 0;
    virtual void cypherLogin() = 0;

    virtual void verification() = 0;
};

class Reg : public Functional
{
public:
    Reg(string name, int password, int login)
        : Functional(name, password, login) {}

    string getName() override
    {
        cout << "Write your name: ";
        cin >> name;
        cypherName();
        return name;
    }

    int getPassword() override
    {
        cout << "Write your password: ";
        cin >> password;
        cypherPassword();
        return password;
    }

    int getLogin() override
    {
        cout << "Write your login: ";
        cin >> login;
        cypherLogin();
        return login;
    }

    void cypherName() override
    {
        hash<string> hasher;
        size_t hashed = hasher(name);
        cout << "Your name hash: " << hashed << endl;
    }

    void cypherPassword() override
    {
        hash<string> hasher;
        size_t hashed = hasher(to_string(password));
        cout << "Your password hash: " << hashed << endl;
    }

    void cypherLogin() override
    {
        hash<string> hasher;
        size_t hashed = hasher(to_string(login));
        cout << "Your login hash: " << hashed << endl;
    }

    void verification() override
    {
        if (name == "Alex" || password == 123 || login == 123)
        {
            cout << "✅ Verification successful! Welcome, " << name << endl;
        }
        else
        {
            cout << "❌ Verification failed! Access denied." << endl;
        }
    }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    Reg user("Default", 1234, 5678);
    user.getName();
    user.getPassword();
    user.getLogin();
    user.verification();

    return 0;
}
