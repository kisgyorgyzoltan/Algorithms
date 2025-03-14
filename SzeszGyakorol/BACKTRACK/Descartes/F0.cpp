/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>

using namespace std;

void descartes(int k, int n, int m, vector<int> &i)
{
	if (k == n + 1)
	{
		for (int sz : i)
		{
			cout << sz << " ";
		}
		cout << endl;
	}
	else
	{
		for (i[k] = 1; i[k] <= m; i[k]++)
		{
			descartes(k + 1, n, m, i);
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> i(n + 1);
	descartes(0, n, m, i);
	return 0;
}
