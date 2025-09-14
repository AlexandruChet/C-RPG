#include <iostream>

using namespace std;
typedef unsigned int uint; // using std + uint

class link
{
public:
    int val;
    link *next;
}; // my main class list

class linklist
{
private:
    link *first;
    link *last; // private paramethers

public:
    linklist() : first(nullptr), last(nullptr) {} // my constructor
    bool is_empty() { return first == nullptr; }

    void push_front(uint x)
    {
        link *tmp = new link; // pointer
        tmp->val = x;
        tmp->next = first;
        first = tmp;
        if (last == nullptr)
            last = tmp;
    }

    void push_back(uint x)
    {
        link *tmp = new link;
        tmp->val = x;
        tmp->next = nullptr;
        if (this->is_empty())
        {
            first = last = tmp;
        }
        else
        {
            last->next = tmp;
            last = tmp;
        }
    }

    void pop_front()
    {
        if (is_empty())
            return;
        link *tmp = first->next;
        delete first;
        first = tmp;
        if (first == nullptr)
            last = nullptr;
    }

    void pop_back()
    {
        if (is_empty())
            return;
        if (first == last)
        {
            delete first;
            first = last = nullptr;
            return;
        }
        link *tmp = first;
        while (tmp->next != last)
        {
            tmp = tmp->next;
        }
        delete last;
        last = tmp;
        last->next = nullptr;
    }

    uint at(uint index)
    {
        if (is_empty())
        {
            throw out_of_range("List is empty");
        }
        link *tmp = first;
        uint count = 0;
        while (tmp != nullptr && count < index)
        {
            tmp = tmp->next;
            count++;
        }
        if (tmp == nullptr)
        {
            throw out_of_range("Index out of range");
        }
        return tmp->val;
    }

    void display()
    {
        link *tmp = first;
        while (tmp != nullptr)
        {
            cout << tmp->val << "\n";
            tmp = tmp->next;
        }
        cout << endl;
    }
};

int main()
{
    linklist test;
    test.push_back(10);
    test.push_back(20);
    test.push_front(30);
    test.push_back(40);

    test.display();

    cout << "Element at index 1: " << test.at(0) << endl;
    cout << "Element at index 2: " << test.at(2) << endl;

    return 0;
}