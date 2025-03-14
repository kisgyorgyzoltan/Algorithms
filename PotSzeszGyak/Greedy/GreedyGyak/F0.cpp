/*
 * Kisgyörgy Zoltán, 532
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

#define INF INT_MAX

using namespace std;

void init(int n, int s, vector<vector<int>>& a, vector<bool>& ismeretlen, vector<int>& d, vector<int>& p)
{
	for (int i = 1; i <= n; i++)
	{
		ismeretlen[i] = true;
		d[i] = a[s][i];
		p[i] = s;
	}
	d[s] = 0;
	ismeretlen[s] = false;
}

int dmin(int& ind, int n, vector<bool>& ismeretlen, vector<int>& d)
{
	int min = INF;
	for (int i = 1; i <= n; i++)
	{
		if (ismeretlen[i])
		{
			if (min > d[i])
			{
				ind = i;
				min = d[i];
			}
		}
	}
	return min;
}

void dijkstra(int n, int s, vector<vector<int>> &a, vector<bool> &ismeretlen, vector<int> &d, vector<int> &p)
{
	init(n, s, a, ismeretlen, d, p);

	int ind;
	while (dmin(ind, n,ismeretlen, d) < INF)
	{
		ismeretlen[ind] = false;
		for (int j = 1; j <= n; j++)
		{
			if (ismeretlen[j] && a[ind][j] < INF)
			{
				int dd = d[ind] + a[ind][j];
				if (dd < d[j])
				{
					d[j] = dd;
					p[j] = ind;
				}
			}
		}
	}
}

int main()
{
	int n, m, s;
	cin >> n >> m >> s;
	vector<vector<int>> a(n + 1, vector<int>(n + 1, INF));
	vector<bool> ismeretlen(n + 1, true);
	vector<int> d(n + 1), p(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[u][v] = w;
	}
	dijkstra(n, s, a, ismeretlen, d, p);
	for (int i = 1; i <= n; i++)
	{
		cout << s << " -> " << i << " = " << d[i] << endl;
	}
	
	return 0;
}
