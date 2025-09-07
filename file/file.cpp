#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Point
{
    Point(double x, double y) : x{x}, y{y} {};
    double x;
    double y;
};

int main()
{
    ofstream out("text.txt", ios::app);
    if (out.is_open())
    {
        out << "Hello World!" << endl;
        out.close();
    }

    string line;
    ifstream in("text.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;
        }
        in.close();
    }

    vector<Point> points{Point{0, 0}, Point{4, 5}, Point{-5, 7}};
    out.open("text.txt");
    if (out.is_open())
    {
        for (const Point &point : points)
        {
            out << point.x << " " << point.y << endl;
        }
        out.close();
    }

    vector<Point> new_points;
    in.open("text.txt");
    if (in.is_open())
    {
        double x, y;
        while (in >> x >> y)
        {
            new_points.push_back(Point(x, y));
        }
        in.close();
    }

    for (const Point &point : new_points)
    {
        cout << "Point X:" << point.x << "\tY:" << point.y << endl;
    }

    return 0;
}
