#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;

class file_manager
{
public:
    void create()
    {
        string folderName = "text";
        if (filesystem::create_directory(folderName))
        {
            cout << "Folder: " << folderName << " created" << endl;
        }
        else
        {
            cout << "Error: " << folderName << endl;
        }
    }

    void write_file()
    {
        ofstream out("text/text.txt");
        if (out.is_open())
        {
            out << "Hello World!" << endl;
            out.close();
        }
        else
        {
            cout << "Error" << endl;
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
        else
        {
            cout << "Error" << endl;
        }
    }

    void read_file()
    {
        string line;
        ifstream in("text/text.txt");
        if (in.is_open())
        {
            while (getline(in, line))
            {
                cout << line << endl;
            }
            in.close();
        }
        else
        {
            cout << "Error" << endl;
        }
    }

    void copy()
    {
        ifstream src("text/text.txt");
        ofstream dest("text/copy.txt");

        if (!src.is_open() || !dest.is_open())
        {
            cout << "Error" << endl;
            return;
        }

        string line;
        while (getline(src, line))
        {
            dest << line << endl;
        }

        src.close();
        dest.close();
        cout << "File copied" << endl;
    }
};

int main()
{
    file_manager fm;
    fm.create();
    fm.write_file();
    fm.write_endl_file();
    fm.read_file();
    fm.copy();
    return 0;
}
