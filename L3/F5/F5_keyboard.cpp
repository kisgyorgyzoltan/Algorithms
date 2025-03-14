/*
 * Kisgyörgy Zoltán, 532
 * L3 - 5. Bontsunk törzstényezőkre egy adott 𝑛 természetes számot!
 */

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void torzstenyezo(unsigned long long n)
{

    vector<unsigned long long> v;

    while (n % 2 == 0)
    {
        v.push_back(2);
        n = n / 2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
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
        }
        else
        {
            cout << v[i];
        }
        if (i < hossz - 1)
        {
            cout << "*";
        }
        i++;
    }
}
int main()
{
    unsigned long long n;
    cin >> n;
    torzstenyezo(n);
    return 0;
}