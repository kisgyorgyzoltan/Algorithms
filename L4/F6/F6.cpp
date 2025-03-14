/*
 * Kisgyörgy Zoltán, 532
 * L4-6 rjunk rekurzív algoritmust, amely kiír egy 𝑛 természetes számot törzstényezőkre
bontva! Ne használjunk egyáltalán ismétlő struktúrát!
 */

#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

bool primRek(unsigned long szam, unsigned long i, double gyok)
{
    if (i <= gyok)
    {
        if (szam % i == 0 || szam % (i + 2) == 0)
        {
            return false;
        }
        return primRek(szam, i + 6, gyok);
    }
    else
    {
        return true;
    }
}

bool primE(unsigned long szam)
{
    if (szam < 2)
    {
		return false;
    }
    else if (szam <= 3)
    {
		return true;
    }
	else if (szam % 2 == 0 || szam % 3 == 0)
	{
		return false;
	}
    else
    {
        return primRek(szam, 5, sqrt(szam));
    }
}

void kiirtt(unsigned long torzst, unsigned long db, bool& elso)
{
    if (db > 1)
    {
        if (elso)
        {
            cout << torzst << "^" << db;
            elso = false;
        }
        else
        {
            cout << "*" << torzst << "^" << db;
        }
    }
    else if (db == 1)
    {
        if (elso)
        {
            cout << torzst;
            elso = false;
        }
        else
        {
            cout << "*" << torzst;
        }
    }
}

void torzstenyezoRek(unsigned long szam, unsigned long torzst, unsigned long db, bool& elso)
{
    if (szam <= 1)
    {
        kiirtt(torzst, db, elso);
    }
    else if (szam % torzst == 0)
    {
		torzstenyezoRek(szam / torzst, torzst, db + 1, elso);
    }
    else
    {
        kiirtt(torzst, db, elso);
        torzstenyezoRek(szam, torzst + 1, 0, elso);
    }
}

void torzstenyezo(unsigned long szam)
{
    if (primE(szam)) 
    {
		cout << szam;
    }
    else
    {
	    bool elso = true;
    	torzstenyezoRek(szam, 2, 0, elso);
    }
}


int main()
{
    unsigned long n;
    cin >> n;
	torzstenyezo(n);
    return 0;
}