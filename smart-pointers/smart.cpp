#include <iostream>
#include <memory>

using namespace std;
typedef unsigned int uint;

class link
{
public:
    int val;
    unique_ptr<link> next;
};

class linklist
{
private:
    unique_ptr<link> first;
    link *last;

public:
    linklist() : first(nullptr), last(nullptr) {}
    bool is_empty() { return first == nullptr; }

    void push_front(uint x)
    {
        auto tmp = make_unique<link>();
        tmp->val = x;
        tmp->next = move(first);
        first = move(tmp);
        if (last == nullptr)
            last = first.get();
    }

    void push_back(uint x)
    {
        auto tmp = make_unique<link>();
        tmp->val = x;
        tmp->next = nullptr;

        if (is_empty())
        {
            last = tmp.get();
            first = move(tmp);
        }
        else
        {
            last->next = move(tmp);
            last = last->next.get();
        }
    }

    void pop_front()
    {
        if (is_empty())
            return;
        first = move(first->next);
        if (first == nullptr)
            last = nullptr;
    }

    void pop_back()
    {
        if (is_empty())
            return;
        if (first.get() == last)
        {
            first.reset();
            last = nullptr;
            return;
        }
        link *tmp = first.get();
        while (tmp->next.get() != last)
        {
            tmp = tmp->next.get();
        }
        tmp->next.reset();
        last = tmp;
    }

    uint at(uint index)
    {
        if (is_empty())
        {
            throw out_of_range("List is empty");
        }
        link *tmp = first.get();
        uint count = 0;
        while (tmp != nullptr && count < index)
        {
            tmp = tmp->next.get();
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
        link *tmp = first.get();
        while (tmp != nullptr)
        {
            cout << tmp->val << "\n";
            tmp = tmp->next.get();
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