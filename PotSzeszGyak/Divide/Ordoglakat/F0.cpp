/*
 * Kisgy�rgy Zolt�n, 532
 * L7-5 Az �rd�glakat f�mgyurukbol �ssze�ll�tott szerkezet. Minden gyurunek van
sz�ra, amelyet k�rbefog a sorrendben k�vetkezo gyuru. Z�rt �llapotban a sz�rakat
k�rbefogja egy ov�lis hurok. Az a c�l, hogy a lakatot kinyissuk, azaz a hurkot
elt�vol�tsuk. A gyuruket balr�l-jobbra 1-tol ??-ig sorsz�mozzuk. Minden l�p�sben
egy gyuru veheto le, vagy teheto fel az al�bbi k�t szab�ly betart�s�val.
1. Az elso gyuru b�rmikor leveheto, illetve felrakhat�.
2. Minden ?? > 1 sorsz�m� gyuru akkor �s csak akkor veheto le, illetve teheto
fel, ha az ?? - 1-edik gyuru fent van, �s minden ?? - 1-n�l kisebb sorsz�m�
gyuru lent van.
A lakat akkor van kinyitva, ha minden gyuru lent van. Adjuk meg a l�p�sek
olyan sorozat�t, amely kinyitja a lakatot!
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
