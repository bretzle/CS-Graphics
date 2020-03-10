#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    ifstream file;
    string line;

    if (argc != 2)
    {
        cout << "Invalid number of arguments." << endl;
        cout << "Pass the loacation of a .stl file to read" << endl;

        return 0;
    }

    file.open(argv[1]);

    if (!file.is_open())
    {
        cout << "File not found" << endl;
        return 0;
    }

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();

    return 0;
}
