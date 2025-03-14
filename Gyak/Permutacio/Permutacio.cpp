#include <iostream>
#include <vector>

using namespace std;

void kiir(int n, vector<int>& v)
{
	for (int i = 1; i <= n; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void permutacio(int n, vector<int>& v, int k)
{
	if (k == n )
	{
		kiir(n, v);
	}
	else
	{
		for (int i = k; i <= n; i++)
		{
			swap(v[i], v[k]);

			permutacio(n, v, k + 1);

			swap(v[i], v[k]);
		}
	}		
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
	permutacio(n, v,1);
}
