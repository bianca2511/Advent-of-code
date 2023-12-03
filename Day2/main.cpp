#include <iostream>
#include <fstream>
#include <string.h>
#include <map>
#include <istream>
#include <vector>

using namespace std;
ifstream f("data.in");

int totalRed = 12;
int totalGreen = 13;
int totalBlue = 14;
int gameTotal = 0;
int main()
{
    string line;
    while (getline(f, line))
    {
        string gameNumber;

        line.erase(line.size()-1);
        line += ';';

        int pos = line.find(":");

        if (pos != string::npos)
        {
            gameNumber = line.substr(5, pos - 5);
            cout << "Game Number: " << gameNumber << std::endl;
        }

        string cubes = line.substr(pos + 2, line.length() - (pos + 2));
        int cubePos = 0;
        cubePos = cubes.find(";", cubePos);
        bool ok = true;
        while ((cubePos != string::npos))
        {
            string cube = cubes.substr(0, cubePos);
            cubes.erase(0, cubePos + 2); // Move past the ';' and the space
            int subtotalRed = 0;
            int subtotalGreen = 0;
            int subtotalBlue = 0;
            // Extract number and color
            int number;
            string color;
            int spacePos = cube.find(" ");
            if (spacePos != string::npos)
            {
                number = stoi(cube.substr(0, spacePos));
                color = cube.substr(spacePos + 1);
                cout<<"Number "<<number<<endl;
                cout<<"Color "<<color<<endl;

                if (color.compare("red") == 0)
                {   
                    subtotalRed += number;
                }
                else if (color.compare("green") == 0)
                {
                    subtotalGreen += number;
                }
                else if (color.compare("blue") == 0)
                {
                    subtotalBlue += number;
                }
            }

            if (subtotalRed > totalRed || subtotalBlue > totalBlue ||
                subtotalGreen > totalGreen)
            {
                ok = false;
            }
            cout<<"subtotal per game"<<subtotalRed<<" "<<subtotalBlue<<" "<<subtotalGreen<<endl;
            cubePos = cubes.find(";", cubePos);
        }

        if (ok == true)
        {
            gameTotal += stoi(gameNumber);
        }
    }
    cout<<gameTotal;

    return 0;
}
