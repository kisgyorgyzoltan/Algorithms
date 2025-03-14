/*
 * Kisgyörgy Zoltán, 532
 * L3 - 5. Bontsunk törzstényezőkre egy adott 𝑛 természetes számot!
 */

#include <iostream>
#include <math.h>
#include <vector>

#include <fstream>

using namespace std;

void torzstenyezo(unsigned long long n)
{
    ofstream g("2149_3_5_3.out");
    vector<unsigned long long> v;

    //while (n % 2 == 0)
    //{
    //    v.push_back(2);
    //    n = n / 2;
    //}

    for (int i = 2; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            v.push_back(i);
            n = n / i;
        }
    }

    if (n > 2)
    {
        v.push_back(n);
    }

    int i = 0, hossz = v.size();
    while (i < hossz)
    {
        int db = 1;
        unsigned long long jelenlegi = v[i];
        if (i + 1 < hossz)
        {
            while (i + 1 < hossz && v[i + 1] == jelenlegi)
            {
                db++;
                i++;
            }
        }
        if (db > 1)
        {
            cout << v[i] << "^" << db;
            g << v[i] << "^" << db;
        }
        else
        {
            cout << v[i];
            g << v[i];
        }
        if (i < hossz - 1)
        {
            cout << "*";
            g << "*";
        }
        i++;
    }
    g.close();
}
int main()
{
    ifstream f("2149_3_5_3.in");
    unsigned long long n;
    // cin >> n;
    f >> n;
    f.close();
    torzstenyezo(n);
    return 0;
}