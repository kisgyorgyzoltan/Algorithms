/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void bor(int n, vector<int>& v)
{
	int k = 0, m = 0;
	for (int i = 1; i <= n; i++)
	{
		k += v[i];
		m += abs(k);
	}
	cout << m;
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
	bor(n, v);
	return 0;
}
