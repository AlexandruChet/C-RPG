#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class file_manager
{
public:
    void write_file()
    {
        ofstream out;

        out.open("text/text.txt");
        if (out.is_open())
        {
            out << "Hello World!" << endl;
            out.close();
        }
    }

    void write_endl_file()
    {
        ofstream out("text/text.txt", ios::app);

        if (out.is_open())
        {
            out << "Hello World" << endl;
            out.close();
        }
    }

    void read_file()
    {
        string line;

        ifstream in(text / text.txt);
        if (in.is_open())
        {
            while (getline(in, line))
            {
                cout << line << endl;
            }
        }
        in.close();
    }
};

int main()
{
    return 0;
}