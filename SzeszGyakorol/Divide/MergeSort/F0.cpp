/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>

using namespace std;

void ossszefesul(vector<int> &v, int b, int k, int j)
{
	int b2 = k + 1; // index a masodik felnek
	if (v[k] <= v[b2]) // ha nem kell osszefesulni mert mar ossze van
	{
		return;
	}

	while (b <= k && b2 <= j)
	{
		if (v[b] <= v[b2])
		{
			b++;
		}
		else
		{
			int ertek = v[b2];
			int index = b2;

			while (index != b)
			{
				v[index] = v[index - 1];
				index--;
			}
			v[b] = ertek;
			b++;
			k++;
			b2++;
		}
	}
}

void mergesort(vector<int>& v, int b, int j)
{
	if (b < j)
	{
		int k = (b + j) / 2;
		mergesort(v, b, k);
		mergesort(v, k + 1, j);
		ossszefesul(v, b, k, j);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	mergesort(v, 1, n);
	for (int i = 1; i <= n; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}
