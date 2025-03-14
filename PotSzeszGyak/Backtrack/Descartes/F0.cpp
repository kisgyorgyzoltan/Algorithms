/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>

using namespace std;
#include <vector>

void descartes(int k, int n, int m, vector<int>& v)
{
	if (k == n + 1)
	{
		for (int i = 1; i <= n; i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}
	else
	{
		for (v[k] = 1; v[k] <= m; v[k]++)
		{
			descartes(k + 1, n, m, v);	
		}
	}
}

int main()
{
	int n, m;
	vector<int> v;
	cin >> n >> m;
	v.resize(n + 1, 0);
	descartes(1, n, m, v);
	return 0;
}
