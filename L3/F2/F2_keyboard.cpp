/*
* Kisgyörgy Zoltán, 532
* L3 - 2. Írjunk algoritmust, amely egy adott 𝑥 páros számot felír két különböző
prímszám összegeként
*/

#include <iostream>
#include <cmath>

using namespace std;

bool primE(unsigned long a)
{
    if (a == 0 || a == 1)
    {
        return false;
    }
	double gyok = sqrt(a);
    for (unsigned long i = 2; i <= gyok; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}

void Goldbach(unsigned long x)
{
    for (unsigned long i = 0; i <= x / 2; i++)
    {
        if (primE(i) && primE(x - i))
        {
            cout << x << " = " << i << " + " << x - i;
            break;
        }
    }
}

int main()
{
    unsigned long x;
    cin >> x;

    if (x % 2 == 0 && x > 6)
    {
        Goldbach(x);
    }
    return 0;
}