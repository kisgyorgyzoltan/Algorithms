/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>

using namespace std;

void osszefesul(int bal, int kozep, int jobb, vector<int>& v)
{
	int bal2 = kozep + 1;
	if (v[kozep] <= v[kozep + 1]) return; // mar ossze van fesulve
	while (bal <= kozep && bal2 <= jobb)
	{
		if (v[bal] <= v[bal2])
		{
			bal++;
		}
		else
		{
			int ertek = v[bal2], index = bal2;
			while (bal != index)
			{
				v[index] = v[index - 1];
				index--;
			}
			v[bal] = ertek;
			bal++;
			kozep++;
			bal2++;
		}
	}
}

void ms(int bal, int jobb, vector<int>& v)
{
	if (bal < jobb)
	{
		int kozep = (bal + jobb) / 2;
		ms(bal, kozep, v);
		ms(kozep + 1, jobb, v);
		osszefesul(bal, kozep, jobb, v);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	ms(0, n - 1, v);
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << " ";
	}
	return 0;
}
