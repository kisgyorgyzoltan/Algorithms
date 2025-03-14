/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>

using namespace std;

void permutaciok(int k, int n, vector<int> &i, vector<bool> &volt)
{
	if (k == n + 1)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << i[j] << " ";
		}
		cout << endl;
	}
	else
	{
		for (i[k] = 1; i[k] <= n; i[k]++)
		{
			if (!volt[i[k]])
			{
				volt[i[k]] = true;
				permutaciok(k + 1, n, i, volt);
				volt[i[k]] = false;
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<bool> volt(n + 1, false);
	vector<int> i(n + 1);
	permutaciok(1, n, i, volt);
	return 0;
}
