/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>

using namespace std;

void reszhalmazok(vector<int>& v, int k, int n)
{
	for (int j = v[k-1] + 1; j <= n; j++)
	{
		v[k] = j;
		for (int i = 1; i <= k; i++)
			cout << v[i] << " ";
		cout << endl;
		reszhalmazok(v, k + 1, n);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n + 1);
	reszhalmazok(v, 1, n);
	return 0;
}
