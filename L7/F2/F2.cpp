/*
 * Kisgyörgy Zoltán, 532
 * L7-2 Adott egy 𝑛 elemű tömb, mely 64 bites valós számokat tartalmaz és egy 𝑘
természetes szám. Határozzuk meg a tömb 𝑘. legkisebb elemét, anélkül, hogy
rendeznénk azt, vagy használnánk az nth_element függvényt!
 */

#include <iostream>
#include <vector>
#include <random>

using namespace std;

void csere(double &a, double &b)
{
    double seged = a;
    a = b;
    b = seged;
}

int feloszt(vector<double> &szamok, int &bal, int &jobb) // Lomuto
{
    int strazsaIndex = bal + rand() % (jobb - bal + 1);
    double strazsa = szamok[strazsaIndex];
    csere(szamok[jobb], szamok[strazsaIndex]); // strazsa a jobb szelen
    strazsaIndex = bal;
    for (int i = bal; i < jobb; i++)
    {
        if (szamok[i] <= strazsa)
        {
            csere(szamok[i], szamok[strazsaIndex]);
            strazsaIndex++;
        }
    }
    csere(szamok[strazsaIndex], szamok[jobb]);
    return strazsaIndex;
}

double quicksort(vector<double> &szamok, int bal, int jobb, int k) // modositott quicksort
{
    if (bal == jobb)
    {
        return szamok[bal];
    }
    int m = feloszt(szamok, bal, jobb);
    if (k == m) // ha a k. legkisebb elem a m. helyen van
        return szamok[k];
    else if (k < m) // ha a k. legkisebb elem a bal resztombben van
        return quicksort(szamok, bal, m - 1, k); // bal resztomb
    else
        return quicksort(szamok, m + 1, jobb, k); // jobb resztomb
    
}

bool novekvoSorrend(vector<double>& szamok)
{
    int n = szamok.size();
    for (int i = 1; i < n; i++)
    {
		if (szamok[i - 1] > szamok[i])
        {
            return false;
        }
	}
	return true;
}

bool csokkenoSorrend(vector<double>& szamok)
{
	int n = szamok.size();
    for (int i = 1; i < n; i++)
    {
        if (szamok[i - 1] < szamok[i])
        {
			return false;
		}
	}
	return true;
}

void quickselect(vector<double>& szamok, int& n, int& k)
{
    if (novekvoSorrend(szamok)) // ha a tomb rendezett akkor a k. legkisebb elem a k. helyen van
    {
        cout << szamok[k - 1];
    }
    else if (csokkenoSorrend(szamok)) // ha a tomb rendezett csokkeno sorrendben akkor a k. legkisebb elem a n-k. helyen van
    {
		cout << szamok[n - k];
	}
    else // ha a tomb nem rendezett akkor meg kell keresni a k. legkisebb elemet
    {
        cout << quicksort(szamok, 0, n - 1, k - 1);
    }
}

void beolvas(vector<double> &szamok, int &n, int &k)
{
    cin >> n >> k;
    szamok.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> szamok[i];
    }
}

int main()
{
    int n, k;
    vector<double> szamok;
    beolvas(szamok, n, k);
    quickselect(szamok, n, k);

    return 0;
}