/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>

using namespace std;
#include <vector>

void reszhalmaz(int k, int n, vector<int>& v, vector<int>& a)
{
	if (k == n + 1)
	{
		for (int i = 1; i <= n; i++)
		{
			if (v[i] == 1)
			{
				cout << a[i] << " ";
			}
		}
		cout << endl;
	}
	else
	{
		for (v[k] = 1; v[k] <= 2; v[k]++)
		{
			reszhalmaz(k + 1, n, v, a);
		}
	}
}

int main()
{
	int n, m;
	vector<int> v, a;
	cin >> n;
	a.resize(n + 1, 0);
	v.resize(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	reszhalmaz(1, n, v, a);
	return 0;
}
