/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>

using namespace std;

void kiir(int i, vector<int>& maxhossz, vector<int>& elozo, vector<int> &v)
{
	if (maxhossz[i] >= 1)
	{
		kiir(elozo[i], maxhossz, elozo, v);
	}
	cout << v[i] << " ";
}

void lh(int n, vector<int>& v)
{
	vector<int> maxhossz(n + 1, 0), elozo(n + 1, 0);
	maxhossz[1] = 1;
	int m = 1;
	for (int i = 2; i <= n; i++)
	{
		maxhossz[i] = 0;
		for (int j = 1; j <= i - 1; j++)
		{
			if (maxhossz[j] > maxhossz[i] && v[i] > v[j])
			{
				maxhossz[i] = maxhossz[j];
				elozo[i] = j;
			}
		}
		maxhossz[i]++;
		if (maxhossz[i] > maxhossz[m])
		{
			m = i;
		}
	}
	cout << maxhossz[m] << endl;
	kiir(m, elozo, elozo, v);
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	lh(n, v);
	return 0;
}
