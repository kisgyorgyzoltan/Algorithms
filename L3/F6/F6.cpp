/*
 * Kisgyörgy Zoltán, 532
 * L3 - 6. Keressük meg adott számmal bezárólag a legtöbb osztójú természetes számot!
 */

#include <iostream>

#include <fstream>

using namespace std;

void legtobboszt(long n)
{
    ofstream g("2149_3_6_3.out");
    if (n == 1)
    {
        cout << 1 << " " << 0;
        g << 1 << " " << 0;
    }
    int *szita = new int[n + 1];
    szita[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        szita[i] = -2;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; j += i)
        {
            szita[j]++;
        }
    }

    int max = 0;
    for (int i = 2; i <= n; i++)
    {
        if (max < szita[i])
        {
            max = szita[i];
        }
    }

    int i = 2;
    while (i <= n && szita[i] != max)
    {
        i++;
    }

    if (i <= n)
    {
        cout << i << " " << max << endl;
        g << i << " " << max << endl;
    }

    g.close();
    delete[] szita;
}
int main()
{
    long n;
    ifstream f("2149_3_6_3.in");
    // cin >> n;
    f >> n;
    f.close();
    if (n >= 1 && n <= 10000000)
    {
        legtobboszt(n);
    }
    return 0;
}