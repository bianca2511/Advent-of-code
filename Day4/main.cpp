#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <math.h>

using namespace std;
ifstream f("data.in");

struct card
{
    int win[250];
    int guess[250];
    int copies;
    int generated_copies[250];
} cards[250];

int n, g, w;

int main()
{

    string line;
    while (getline(f, line))
    {

        string cardNumber;
        int pos = line.find(":");

        if (pos != string::npos)
        {
            cardNumber = line.substr(5, pos - 5);
            // cout << "Game Number: " << cardNumber << endl;
        }

        string games = line.substr(pos + 2, line.length() - (pos + 2));
        // cout << games << endl;

        int posDivider = games.find("|");
        string winners = games.substr(0, posDivider - 1);
        string guesses = games.substr(posDivider + 2, games.length() - 1);

        // cout << winners << endl;
        // cout << guesses << endl;
        // cout << endl;

        char *dup = strdup(winners.c_str());
        char *p = strtok(dup, " ");
        w = 0;
        while (p)
        {
            cards[n].win[w++] = atoi(p);
            p = strtok(NULL, " ");
        }

        free(dup);

        char *dup2 = strdup(guesses.c_str());
        char *p2 = strtok(dup2, " ");
        g = 0;
        while (p2)
        {
            cards[n].guess[g++] = atoi(p2);
            p2 = strtok(NULL, " ");
        }
        free(dup2);
        n++;
    }

    int counter;
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        int no = 0;
        counter = 0;
        for (int j = 0; j < w; j++)
        {
            for (int k = 0; k < g; k++)
            {
                if (cards[i].win[j] == cards[i].guess[k])
                {
                    counter++;
                }
            }
        }
        if (counter > 0)
        {
            cards[i].copies = counter;

            for (int it = i + 2; it < i + cards[i].copies; it++)
            {
                cards[i].generated_copies[no++] = it;
            }
            // total += pow(2, counter - 1);
        }
        cout << "Card " << i + 1 << " generates " << cards[i].copies << " cards ";
        for (int it = 0; it < no; it++)
        {
            cout << cards[i].generated_copies[it] << " ";
        }
        cout << endl;
    }
    // cout << "grand total " << total;

    return 0;
}