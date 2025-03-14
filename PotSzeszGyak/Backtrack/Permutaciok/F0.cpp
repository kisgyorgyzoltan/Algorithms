/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>

using namespace std;
#include <vector>

void perm(int k, int n, vector<bool>& volt, vector<int>& a)
{
	if (k == n + 1)
	{
		for (int i = 1; i <= n; i++)
		{
			if (volt[i] == 1)
			{
				cout << a[i] << " ";
			}
		}
		cout << endl;
	}
	else
	{
		for (a[k] = 1; a[k] <= n; a[k]++)
		{
			if (!volt[a[k]])
			{
				volt[a[k]] = true;
				perm(k + 1, n, volt, a);
				volt[a[k]] = false;
			}
		}
	}
}

int main()
{
	int n, m;
	vector<int> a;
	vector<bool> v;
	cin >> n;
	a.resize(n + 1, 0);
	v.resize(n + 1, false);
	perm(1, n, v, a);
	return 0;
}
