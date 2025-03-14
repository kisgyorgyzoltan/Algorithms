/*
* Kisgy�rgy Zolt�n, 532
* L1 - 9.Sz�m�tsuk ki, h�ny napot �lt�nk a mai nappal bez�r�lag! Ha valaki janu�r
    1.-�n sz�letett, akkor janu�r 2.-�n �lt 1 napot.
*/

#include <iostream>

using namespace std;

int dbszoko(int ev, int honap, int nap)
{

    if (honap <= 2)
    {
        ev--;
    }

    return ev / 4 - ev / 100 + ev / 400;
}

int osszesnap(int ev, int honap, int nap)
{
    int honapnapok[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    long napok = dbszoko(ev, honap, nap) + (ev * 365) + nap;
    for (int i = 1; i < honap; i++)
    {
        napok += honapnapok[i];
    }
    return napok;
}

int main()
{
    char x;
    int szev, szh, szn, ev, h, n;
    
    cin >> szev >> x >> szh >> x >> szn;
    cin >> ev >> x >> h >> x >> n;
    
    cout << osszesnap(ev, h, n) - osszesnap(szev, szh, szn);

    return 0;
}
