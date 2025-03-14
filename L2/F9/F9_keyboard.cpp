/*
* Kisgyörgy Zoltán, 532
* L2 - 9. Ismert sejtés, miszerint ha egy adott 𝑛 természetes számot ismételten alávetünk
    a következő feldolgozásnak, eljutunk az 1-es számhoz: ha 𝑛 páros, akkor elosztjuk
    2-vel, ha 𝑛 páratlan, megszorozzuk 3-mal és az eredményhez hozzáadunk 1-et.
    Azoknak a lépéseknek a számát, amelyek egy adott 𝑛-ből az 1-hez vezetnek,
    karakterisztikának nevezzük. Írjunk programot, amely meghatározza azt az 𝑛
    számot, amely az [𝑥, 𝑦] intervallumhoz tartozik és amelynek a karakterisztikája
    a legnagyobb!
*/

#include <iostream>

using namespace std;

void beolvas(int& x, int& y)
{
    cin >> x;
    cin >> y;
}
int feldolgoz(int n)
{
    if (n == 1) return 0;
	int db = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
			n = n * 3 + 1;
        }
        db++;
    }
	return db;
}
void legnagyobb(int x, int y)
{
    int max = x, karmax = feldolgoz(x);
    for (int i = x + 1; i <= y; i++)
    {
        int ifel = feldolgoz(i);
        if ((ifel >= karmax) && (i > max))
        {
            max = i;
            karmax = ifel;
        }
    }
    cout << max << " " << karmax;
}
int main()
{
    int x, y;
    beolvas(x, y);
    legnagyobb(x, y);
    return 0;
}