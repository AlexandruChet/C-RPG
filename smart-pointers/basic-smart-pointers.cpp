#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct Test
{
    Test() { cout << "Created\n"; }
    ~Test() { cout << "Destroyed\n"; }
};

int main()
{
    unique_ptr<Test> p1 = make_unique<Test>();
    unique_ptr<Test> p2 = move(p1); // this make delete function

    shared_ptr<Test> p3 = make_shared<Test>();
    {
        shared_ptr<Test> p4 = p3;
        cout << "Use count: " << p3.use_count() << "\n";
    }
    cout << "Use count: " << p3.use_count() << "\n"; // count

    shared_ptr<Test> p5 = make_shared<Test>();
    weak_ptr<Test> wp = p5;

    cout << "Use count: " << p1.use_count() << "\n";

    if (auto sp = wp.lock())
    {
        cout << "Object is alive\n";
    }
    else
    {
        cout << "Object already destroyed\n";
    }
    return 0;
}