/*
* Kisgyörgy Zoltán, 532
* L1 - 10.
* Írjunk ki egy, a 60-as számrendszerben megadott nemnegatív számot a 10-es
    számrendszerben! A 60-as számrendszer számjegyei: 0,1, . . . , 9, (10), (11), . . . ,
    (59).
*/

#include <iostream>
#include <cstring>

using namespace std;

void tizbehatvan(char be[])
{
    bool belefer = true;
    int szamjegyek[150];
    for (int i = 0; i < 150; i++)
    {
        szamjegyek[i] = 0;
    }
    int seged, dbszj = -1;
    unsigned long long sz = 1, eredmeny = 0;
    for (int i = strlen(be) - 1; i >= 0; i--)
    {
        if (be[i] == ')')
        {
            seged = (10 * ((be[i - 2] - '0')) + (be[i - 1]) - '0');
            i = i - 3;
            dbszj++;
            szamjegyek[dbszj] = seged;
        }
        else
        {
            seged = be[i] - '0';
            dbszj++;
            szamjegyek[dbszj] = seged;
        }
    }

    for (int i = 0; i <= dbszj; i++)
    {
        if (eredmeny + (szamjegyek[i] * sz) < eredmeny)
        {
            belefer = false;
            break;
        }
        eredmeny += (szamjegyek[i] * sz);
        sz *= 60;
    }

    if (belefer)
    {
        cout << eredmeny << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    char be[150];
    cin.get(be, 150);
    tizbehatvan(be);

    return 0;
}
