#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cstdio>
#include <windows.h>

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
            cout << "Folder already exists: " << folderName << endl;
        }
    }

    void write_file()
    {
        ofstream out1("text/text.txt");
        if (out1.is_open())
        {
            out1 << "Hello World!" << endl;
            out1.close();
        }
        else
        {
            cout << "Error opening text.txt" << endl;
        }

        ofstream out2("text/deleted.txt");
        if (out2.is_open())
        {
            out2 << "Hello World!" << endl;
            out2.close();
        }
        else
        {
            cout << "Error opening deleted.txt" << endl;
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
            cout << "Error appending to text.txt" << endl;
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
            cout << "Error reading text.txt" << endl;
        }
    }

    void copy()
    {
        ifstream src("text/text.txt");
        ofstream dest("text/copy.txt");

        if (!src.is_open() || !dest.is_open())
        {
            cout << "Error copying file" << endl;
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

    void delete_file()
    {
        const char *filename = "text/deleted.txt";

        if (remove(filename) == 0)
        {
            cout << "File " << filename << " deleted" << endl;
        }
        else
        {
            cerr << "Error deleting " << filename << endl;
        }
    }

    void rename_file()
    {
        string old_name = "text/copy.txt";
        string new_name = "text/copied.txt";

        if (filesystem::exists(old_name))
        {
            try
            {
                filesystem::rename(old_name, new_name);
                cout << "File renamed " << old_name << " → " << new_name << endl;
            }
            catch (const filesystem::filesystem_error &e)
            {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else
        {
            cout << "File " << old_name << " not found" << endl;
        }
    }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    file_manager fm;

    fm.create();
    fm.write_file();
    fm.write_endl_file();
    fm.read_file();
    fm.copy();
    fm.rename_file();
    fm.delete_file();
    return 0;
}
