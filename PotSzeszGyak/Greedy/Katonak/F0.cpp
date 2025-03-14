/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <map>

using namespace std;

void katonak(int n, int m, map<int, int>& kezd, map<int, int>& vegz)
{
	if (n <= 1 && m <= 0)
	{
		cout << "igen";
	}
	else
	{
		int maxVegz = vegz.rbegin()->first;
		for (int i = 1; i <= maxVegz; i++)
		{
			if (kezd[i])
			{
				if (n == 0 || n - kezd[i] < 0)
				{
					cout << "nem";
					return;
				}
				else
				{
					n -= kezd[i];
				}
			}
			if (vegz[i])
			{
				n += vegz[i];
			}
		}
		if (n < 0)
		{
			cout << "nem";
		}
		else
		{
			cout << "igen";
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	map<int, int> kezd, vegz;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		kezd[a]++;
		vegz[b]++;
	}
	katonak(n, m, kezd, vegz);
	return 0;
}
