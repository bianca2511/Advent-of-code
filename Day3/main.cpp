#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;
ifstream f("data.in");

char matrix[200][200];

struct number
{
    int pos_i, pos_j;
    int n;
    int size;
} numbers[10000];

// ttttttttttt
// lx--------r
// bbbbbbbbbbb

bool isstar(char c)
{
    if (c == '*')
    {
        return true;
    }
    return false;
}

int main()
{
    string line;
    int k = 0;
    int n = 0;

    while (getline(f, line))
    {
        int length = line.length();
        for (int i = 0; i < length; i++)
        {
            matrix[k][i] = line[i];
            if (line[i] == '.')
            {
                matrix[k][i] = ' ';
            }
        }
        k++;
        n = length;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    k += 6;
    n += 6;

    for (int i = n - 6; i >= 0; i--)
    {
        for (int j = k - 6; j >= 0; j--)
        {
            matrix[i + 3][j + 3] = matrix[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < k; j++)
        {
            matrix[i][j] = 'a';
        }
    }

    for (int i = n - 3; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            matrix[i][j] = 'a';
        }
    }

    for (int j = k; j >= k - 3; j--)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][j] = 'a';
        }
    }

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][j] = 'a';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int no = 0;
    for (int i = 0; i < n; i++)
    {
        char line[1000] = {0};
        for (int j = 0; j < k; j++)
        {
            line[j] = matrix[i][j];
        }

        char *p = strtok(line, "!#$%&'()*+,-./:;<=>?@[^_`{|}~a ");
        while (p)
        {
            numbers[no].n = atoi(p);
            numbers[no].pos_i = i;
            numbers[no].pos_j = p - line;
            numbers[no].size = strlen(p);
            no++;

            p = strtok(NULL, "!#$%&'()*+,-./:;<=>?@[^_`{|}~a ");
        }
    }

    // for (int i = 0; i < no; i++)
    // {
    //     cout << numbers[i].n << " ";
    //     cout << numbers[i].size << " ";
    //     cout << numbers[i].pos_i << " " << numbers[i].pos_j;
    //     cout << endl;
    // }

    int total = 0;
    for (int poo = 0; poo < no; poo++)
    {
        bool oki = false;
        int i = numbers[poo].pos_i;

        for (int poopie = 0; poopie < numbers[poo].size; poopie++)
        {
            int j = numbers[poo].pos_j + poopie;

            if ((ispunct(matrix[i - 1][j]) || ispunct(matrix[i - 1][j - 1]) || ispunct(matrix[i][j - 1]) || ispunct(matrix[i + 1][j - 1]) ||
                 ispunct(matrix[i + 1][j]) || ispunct(matrix[i + 1][j + 1]) || ispunct(matrix[i][j + 1]) || ispunct(matrix[i - 1][j + 1])))
            {
                oki = true;
            }
        }

        if (oki == true)
        {
            cout << numbers[poo].n << " ";
            total += numbers[poo].n;
        }
    }

    cout << endl<<"///////////////////////////////////////////////////////////////////////////////////////" << endl;
    int totalgears = 0;
    for (int i = 0; i < n; i++)
    {   
        for (int j = 0; j < k; j++)
        {
            if (isstar(matrix[i][j]))
            {   int ratio = 0;
                int neighbors[9] = {0};
                int neighbours_count = 0;

                for (int poo = 0; poo < no; poo++)
                {
                    int top = numbers[poo].pos_i - 1;
                    int left = numbers[poo].pos_j - 1;
                    int right = numbers[poo].pos_j + numbers[poo].size;
                    int bottom = numbers[poo].pos_i + 1;

                    if (i <= bottom && i >= top && j >= left && j <= right)
                    {
                        neighbors[neighbours_count++] = poo;
                    }
                }

                cout<<neighbours_count<<" ";

                if (neighbours_count == 2)
                {
                     ratio = numbers[neighbors[0]].n * numbers[neighbors[1]].n;
                }
                totalgears += ratio;
            }
        }
        
    }

    cout<<totalgears;

    return 0;
}