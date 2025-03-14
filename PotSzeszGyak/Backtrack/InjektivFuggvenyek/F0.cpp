/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>

using namespace std;

void injektiv(int k, int n, int m, vector<int> &v, vector<bool> &s)
{
	if (k <= n)
	{
		for (int i = 1; i <= m; i++)
		{
			v[k] = i;
			if (!s[i])
			{
				s[i] = true;
				injektiv(k + 1, n, m, v, s);
				s[i] = false;
			}
		}
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1, 0);
	vector<bool> s(m + 1, false);
	injektiv(1, n, m, v, s);
	return 0;
}
