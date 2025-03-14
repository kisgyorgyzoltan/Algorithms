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

long long lnKozepOsszeg(vector<long>& v, int bal, int kozep, int jobb)
{
	long long osszeg = 0, balOsszeg = LLONG_MIN, jobbOsszeg = LLONG_MIN;
	for (int i = kozep; i >= bal; --i)
	{
		osszeg += v[i];
		if (osszeg > balOsszeg)
			balOsszeg = osszeg;
	}

	osszeg = 0;
	for (int i = kozep; i <= jobb; ++i)
	{
		osszeg += v[i];
		if (osszeg > jobbOsszeg)
			jobbOsszeg = osszeg;
	}

	return max(balOsszeg + jobbOsszeg - v[kozep], balOsszeg, jobbOsszeg);
}

long long lnOsszeg(vector<long> &v, int bal, int jobb)
{
	if (bal > jobb)
	{
		return LLONG_MIN;
	}
	if (bal == jobb)
	{
		return v[bal];
	}
	int kozep = (bal + jobb) / 2;
	return max(lnOsszeg(v, bal, kozep), lnOsszeg(v, kozep + 1, jobb), lnKozepOsszeg(v, bal, kozep, jobb));
}

void beolvas(vector<long>& v, int &n)
{
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
}

int main()
{
	int n;
	vector<long> v;
	beolvas(v, n);
	cout << lnOsszeg(v, 0, n - 1) << endl;
	return 0;
}