/*
 * Kisgyörgy Zoltán, 532
 */

#include <iostream>
#include <vector>

using namespace std;

bool novekvo(vector<double>& v, int n)
{
	for (int i = 1; i < n; i++)
	{
		if (v[i - 1] > v[i]) return false;
	}
	return true;
}

bool csokkeno(vector<double>& v, int n)
{
	for (int i = 1; i < n; i++)
	{
		if (v[i - 1] < v[i]) return false;
	}
	return true;
}

void csere(double& a, double& b)
{
	double seged = a;
	a = b;
	b = seged;
}

int feloszt(vector<double>& szamok, int bal, int jobb) // Lomuto
{
	double strazsa = szamok[jobb];
	int i = bal;
	for (int j = bal; j < jobb; j++)
	{
		if (szamok[j] <= strazsa)
		{
			csere(szamok[j], szamok[i]);
			i++;
		}
	}
	csere(szamok[i], szamok[jobb]);
	return i;
}

double qs(vector<double>& szamok, int bal, int jobb, int k) // modositott quicksort
{
	if (bal <= jobb)
	{
		if (bal == jobb)
		{
			return szamok[bal];
		}
		int m = feloszt(szamok, bal, jobb);
		if (k == m) // ha a k. legkisebb elem a m. helyen van
			return szamok[k];
		else if (k < m) // ha a k. legkisebb elem a bal resztombben van
			return qs(szamok, bal, m - 1, k); // bal resztomb
		else
			return qs(szamok, m + 1, jobb, k); // jobb resztomb
	}
}


double kadik(int n, vector<double>& v, int k)
{
	if (novekvo(v, n))
	{
		return v[k - 1];
	}
	else if (csokkeno(v, n))
	{
		return v[n - k];
	}
	else
	{
		return qs(v, 0, n - 1, k - 1);
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<double> v(n, 0), g;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	
	double sajat = kadik(n, v, k);
	cout << sajat;
	return 0;
}
