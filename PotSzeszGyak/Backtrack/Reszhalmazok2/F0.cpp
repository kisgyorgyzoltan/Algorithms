/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>

using namespace std;

void reszhalmazok(int k, vector<int>& v, int n)
{
	for (int j = v[k-1] + 1; j <= n; j++)
	{
		v[k] = j;
		for (int i = 1; i <= k; i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
		reszhalmazok(k + 1, v, n);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i <= n; i++)
	{
		v.push_back(i);
	}
	reszhalmazok(1, v, n);
	return 0;
}
