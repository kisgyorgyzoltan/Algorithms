/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int max(int a, int b, int c)
{
	return max(a, max(b, c));
}

int kozepOsszeg(int bal, int kozep, int jobb, vector<int>& v)
{
	int osszeg = 0, balMax = INT_MIN, jobbMax = INT_MIN;
	for (int i = kozep; i >= bal; i--)
	{
		osszeg += v[i];
		if (osszeg > balMax)
		{
			balMax = osszeg;
		}
	}
	osszeg = 0;
	for (int i = kozep; i <= jobb; i++)
	{
		osszeg += v[i];
		if (osszeg > jobbMax)
		{
			jobbMax = osszeg;
		}
	}
	return max(balMax + jobbMax - v[kozep], balMax, jobbMax);
}

int osszeg(int bal, int jobb, vector<int>& v)
{
	if (bal == jobb) return v[bal];
	else if (bal < jobb)
	{
		int kozep = (bal + jobb) / 2;
		return max(osszeg(bal, kozep, v), osszeg(kozep + 1, jobb, v), kozepOsszeg(jobb, kozep, bal, v));
	}
	else
	{
		return INT_MIN;
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	cout << osszeg(0, n - 1, v);
	return 0;
}
