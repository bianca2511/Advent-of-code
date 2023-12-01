#include <iostream>
#include <fstream>
#include <string.h>
#include <map>
#include <istream>

using namespace std;
ifstream f("data.in");
ofstream g("out.zach");
int total;
string wordyNumbers[10] = {"zeroplsingore","one", "two", "three", "four", "five", "six", "seven","eight","nine"};
int main()
{
    string line;
    while(getline(f, line))
    {
        int number =0;
        ///find the first digit in the word
        int firstNumber = 0;
        int firstDigitIndex = 1000;
        int lastDigitIndex = -1000;
        int lastNumber = 0;
        for(int i = 0; i < line.length(); i++)
        {
            if(isdigit(line[i]))
            {
                firstNumber = ((int) line[i] - '0');
                firstDigitIndex = i;
                break;
            }
        }

        for(int i = line.length(); i>=0; i--)
        {
            if(isdigit(line[i]))
            {
                lastNumber = ((int) line[i] - '0');
                lastDigitIndex = i;
                break;
            }
        }

        /// find words in the line, choose the word that appears first
        int firstWordIndex = 1000;
        int firstWordDigit = 0;
        int lastWordIndex = -1000;
        int lastWordDigit = 0;
        for(int i=1; i<=9; i++)
        {
            int current1 = line.find(wordyNumbers[i]);
            if(current1 != string::npos)
            {
                if(current1 < firstWordIndex)
                {
                    firstWordIndex = current1;
                    firstWordDigit = i;
                }

            }
            int current2 = line.rfind(wordyNumbers[i]);
            if(current2 != string::npos)
            {
                if(current2 > lastWordIndex)
                {
                    lastWordIndex = current2;
                    lastWordDigit = i;
                }

            }
        }

        /// choose between the found digit or the found number for first
        // cout<<"digit index: "<<firstDigitIndex<<"; "<<"word index: "<<firstWordIndex<<endl;
        if(firstWordIndex < firstDigitIndex)
        {
            firstNumber = firstWordDigit;
        }

        /// choose between the found digit or the found number for last
        if(lastWordIndex > lastDigitIndex)
        {
            lastNumber = lastWordDigit;
        }
        number = firstNumber *10 + lastNumber;
        g<<number<<endl;

        total += number;
    }
    g << total;
    f.close();
    return 0;
}
