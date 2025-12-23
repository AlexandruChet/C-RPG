#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream file("text.txt");

    file << "Hello world\n";
    file << "C++ fstream";

    file.close();

    ifstream file_read("text.txt");
    string line;

    while (getline(file_read, line))
    {
        cout << line << endl;
    }

    file_read.close();

    return 0;
}
