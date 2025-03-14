/*
 * Kisgyörgy Zoltán, 532
 * L6-1 Adott egy 𝑛 × 𝑚-es mátrix. Határozzuk meg azt a legnagyobb 𝑛 elemű
összeget, amelyet úgy kapunk meg, hogy minden elem a mátrix különböző
soraiból “származik” és az 𝑖. sorból kiválasztott elem kisebb mint az 𝑖+ 1. sorból
kiválasztott elem.
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void beolvas(int& n, int& m, vector<vector<long>>& v)
{
	cin >> n >> m;
	v.resize(n, vector<long>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
		}
	}
}

long divide(vector<vector<long>>& v, int bal, int jobb, long sorelem, long& osszeg)
{
	if (bal == jobb)
	{
		long max = LONG_MIN;
		for (long i : v[bal])
		{
			if (i > max && i < sorelem)
			{
				max = i;
			}
		}
		osszeg += max;
		return max;
	}
	int kozep = (bal + jobb) / 2;
	long jobbElem = divide(v, kozep + 1, jobb, sorelem, osszeg);
	long balElem = divide(v, bal, kozep, jobbElem, osszeg);
	if (balElem == LONG_MIN || jobbElem == LONG_MIN || balElem >= jobbElem)
	{
		osszeg = LONG_MIN;
	}
	return balElem;
}

int main()
{
	int n, m;
	long osszeg = 0;
	vector<vector<long>> v;
	beolvas(n, m, v);
	divide(v, 0, n - 1, LONG_MAX, osszeg);

	if (osszeg == LONG_MIN)
	{
		cout << "nincs megoldas";
	}
	else
	{
		cout << osszeg << endl;
	}

	return 0;
}
