#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define vegtelen INT_MAX

void init(int n, vector<bool>& ismeretlen, vector<int>& p, vector<int>& d, vector<vector<int>> a,int s)
{
	for (int i = 1; i <= n; i++)
	{
		d[i] = a[s][i];
		ismeretlen[i] = true;
		p[i] = s;
	}
	ismeretlen[s] = false;
	d[s] = 0;
}

int dmin(int n, vector<bool> ismeretlen, vector<int> d, int &ind)
{
	int min = vegtelen;
	for (int i = 1; i <= n; i++)
	{
		if (ismeretlen[i])
		{
			if (d[i] < min)
			{
				min = d[i];
				ind = i;
			}
		}
	}
	return min;
}

void dijkstra(int n, int m, vector<vector<int>> a, int s)
{
	vector<bool> ismeretlen(n + 1);
	vector<int> p(n + 1), d(n + 1);
	init(n, ismeretlen, p, d, a, s);
	int ind;

	while (dmin(n,ismeretlen,d,ind) < vegtelen)
	{
		ismeretlen[ind] = false;
		for (int i = 1; i <= n; i++)
		{
			if (ismeretlen[i] && a[ind][i] < vegtelen)
			{
				int dd = d[ind] + a[ind][i];
				if (dd < d[i])
				{
					d[i] = dd;
					p[i] = ind;
				}
			}
		}
	}
	cout << "d:\n";
	for (int i = 1; i <= n; i++)
	{
		cout << d[i] << " ";
	}
	cout << "\np:\n";
	for (int i = 1; i <= n; i++)
	{
		cout << p[i] << " ";
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n + 1, vector<int>(n + 1, vegtelen));
	for (int i = 1; i <= m; i++)
	{
		int u, v, s;
		cin >> u >> v >> s;
		a[u][v] = s;
	}
	int s = 1;
	dijkstra(n, m, a, s);

	return 0;
}