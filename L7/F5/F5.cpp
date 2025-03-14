/*
 * Kisgyörgy Zoltán, 532
 * L7-5 Az ördöglakat fémgyűrűkből összeállított szerkezet. Minden gyűrűnek van
szára, amelyet körbefog a sorrendben következő gyűrű. Zárt állapotban a szárakat
körbefogja egy ovális hurok. Az a cél, hogy a lakatot kinyissuk, azaz a hurkot
eltávolítsuk. A gyűrűket balról-jobbra 1-től 𝑛-ig sorszámozzuk. Minden lépésben
egy gyűrű vehető le, vagy tehető fel az alábbi két szabály betartásával.
1. Az első gyűrű bármikor levehető, illetve felrakható.
2. Minden 𝑖 > 1 sorszámú gyűrű akkor és csak akkor vehető le, illetve tehető
fel, ha az 𝑖 − 1-edik gyűrű fent van, és minden 𝑖 − 1-nél kisebb sorszámú
gyűrű lent van.
A lakat akkor van kinyitva, ha minden gyűrű lent van. Adjuk meg a lépések
olyan sorozatát, amely kinyitja a lakatot!
 */

#include <iostream>

using namespace std;

void felGyuruk(int n);

void leGyuruk(int n)
{
    if (n == 1) // alapeset 1 gyuru
    {
        cout << 1 << " " << 1 << endl;
    }
    else if (n == 2) // alapeset 2 gyuru
    {
        cout << 1 << " " << 2 << endl;
        cout << 1 << " " << 1 << endl;
        return;
    }
    else // 3 vagy tobb gyuru
    {
        leGyuruk(n - 2);
        cout << 1 << " " << n << endl;
        felGyuruk(n - 2);
        leGyuruk(n - 1);
    }
}

void felGyuruk(int n)
{
    if (n == 1) // alapeset 1 gyuru
    {
        cout << 2 << " " << 1 << endl;
    }
    else if (n == 2) // alapeset 2 gyuru
    {
        cout << 2 << " " << 1 << endl;
        cout << 2 <<" " << 2 << endl;
    }
    else // 3 vagy tobb gyuru
    {
        felGyuruk(n - 1);
        leGyuruk(n - 2);
        cout << 2 << " " << n << endl;
        felGyuruk(n - 2);
    }
}


int main()
{
    int n;
    cin >> n;
    leGyuruk(n);
    return 0;
}
