#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <sstream>

using namespace std;

int main(int argc, char **argv)
{
    ifstream file;
    string line;

    int num_facets = 0;
    bool in_facet = false;

    float minX = numeric_limits<float>::max();
    float minY = numeric_limits<float>::max();
    float minZ = numeric_limits<float>::max();

    float maxX = -numeric_limits<float>::max();
    float maxY = -numeric_limits<float>::max();
    float maxZ = -numeric_limits<float>::max();

    if (argc != 2)
    {
        cout << "Invalid number of arguments." << endl;
        cout << "Pass the loacation of a .stl file to read" << endl;

        return 0;
    }

    string name = string(argv[1]);
    if (name.substr(name.find_last_of(".") + 1) != "stl")
    {
        cout << "File must be a .stl file" << endl;
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
        if (line.find("facet") != string::npos && line.find("endfacet") == string::npos)
        {
            num_facets++;
            in_facet = true;
            cout << "Facet " << num_facets << ": " << endl;
        }
        else if (line.find("endfacet") != string::npos)
        {
            in_facet = false;
        }
        else if (line.find("vertex") != string::npos && in_facet)
        {
            stringstream str_strm(line);
            string word;
            float x, y, z;
            str_strm >> word;
            str_strm >> x;
            str_strm >> y;
            str_strm >> z;

            minX = min(x, minX);
            minY = min(y, minY);
            minZ = min(z, minZ);

            maxX = max(x, maxX);
            maxY = max(y, maxY);
            maxZ = max(z, maxZ);

            cout << "\tX: " << x << " Y: " << y << " Z: " << z << endl;
        }
    }

    file.close();

    cout << "Number of facets: " << num_facets << endl;
    cout << endl;
    cout << "Min X: " << minX << " Max X: " << maxX << endl;
    cout << "Min Y: " << minY << " Max Y: " << maxY << endl;
    cout << "Min Z: " << minZ << " Max Z: " << maxZ << endl;

    return 0;
}
