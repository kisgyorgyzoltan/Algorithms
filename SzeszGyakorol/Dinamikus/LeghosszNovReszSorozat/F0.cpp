/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>

using namespace std;

void kiir(int index, vector<int>& maxHossz, vector<int>& a, vector<int>& elozo)
{
	if (maxHossz[index] > 1)
	{
		kiir(elozo[index], maxHossz, a, elozo);
	}
	cout << a[index] << " ";
}

void leghosszabbNovRS(int n, vector<int>& a)
{
	int m = 1;
	vector<int> elozo(n + 1), maxHossz(n + 1, 0);
	maxHossz[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		maxHossz[i] = 0;
		for (int j = 1; j <= i-1; j++)
		{
			if (maxHossz[j] > maxHossz[i] && a[i] > a[j])
			{
				maxHossz[i] = maxHossz[j];
				elozo[i] = j;
			}
		}
		maxHossz[i]++;
		if (maxHossz[m] < maxHossz[i])
		{
			m = i;
		}
	}
	kiir(m, maxHossz, a, elozo);
	cout << endl;
	cout << maxHossz[m];
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	leghosszabbNovRS(n, a);
	return 0;
}
