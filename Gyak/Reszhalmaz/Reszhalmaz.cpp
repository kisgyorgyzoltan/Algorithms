#include <iostream>
#include <vector>

using namespace std;

void kiir(vector<int> v, int k)
{
	for (int i = 1; i <= k; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void reszhalmazok(vector<int> v, int k, int n)
{
	for (int i = v[k-1] + 1; i <= n; i++)
	{
		v[k] = i;
		kiir(v, k);
		reszhalmazok(v, k + 1, n);
	}
}

int main()
{
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	reszhalmazok(v, 1, 3);
	return 0;
}