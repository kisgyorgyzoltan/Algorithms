/*
 * Kisgyörgy Zoltán, 532
 * L7-3 Adott egy 𝑛 egész számot tartalmazó sorozat. Határozzuk meg azt a legnagyobb összeget, amelyet a tömb egymás utáni elemeinek összeadásával kaphatunk
(vagyis a legnagyobb összegű tömbszakaszt keressük).
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long long max(long long a, long long b, long long c)
{
	if (a > b && a > c)
		return a;
	if (b > a && b > c)
		return b;
	return c;
}

long long kozepOsszeg(vector<long>& v, int bal, int jobb, int kozep)
{
	long long osszeg = 0, balOsszeg = LLONG_MIN, jobbOsszeg = LLONG_MIN;
	for (int i = kozep; i >= bal; i--)
	{
		osszeg += v[i];
		if (osszeg > balOsszeg)
		{
			balOsszeg = osszeg;
		}
	}

	osszeg = 0;
	for (int i = kozep; i <= jobb; i++)
	{
		osszeg += v[i];
		if (osszeg > jobbOsszeg)
		{
			jobbOsszeg = osszeg;
		}
	}
	return max(balOsszeg + jobbOsszeg - v[kozep], balOsszeg, jobbOsszeg);
}


long long osszeg(int bal, int jobb, vector<long>& szamok)
{
	if (bal > jobb)
	{
		return LLONG_MIN;
	}
	if (bal == jobb)
	{
		return szamok[bal];
	}
	int kozep = (bal + jobb) / 2;
	return max(osszeg(bal, kozep, szamok), osszeg(kozep + 1, jobb, szamok), kozepOsszeg(szamok, bal, jobb, kozep));	
}

int main()
{
	int n;
	cin >> n;
	vector<long> szamok(n, 0);
	for (int i = 0; i <n; i++)
	{
		cin >> szamok[i];
	}

	cout << osszeg(0, n - 1, szamok);
	return 0;
}
