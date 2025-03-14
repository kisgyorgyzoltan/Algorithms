/*
 * Kisgyörgy Zoltán, 532
 */

#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

#define INF INT_MAX

int dmin(int n, vector<bool> &ismeretlen, vector<int>& d, int& ind)
{
	int min = INF;
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

void dijkstra(int n, vector<bool>& ismeretlen, vector<int>& d, vector<vector<int>> &a, vector<int>& p)
{
	int ind;
	while (dmin(n, ismeretlen, d, ind) < INF)
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
	vector<bool> ismeretlen(n + 1, true);
	vector<int> d(n + 1), p(n + 1);
	vector < vector<int>> a(n + 1, vector<int>(n + 1, INF));
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[u][v] = w;
	}
	
	for (int i = 1; i <= n; i++)
	{
		d[i] = a[s][i];
		p[i] = s;
	}
	ismeretlen[s] = false;
	d[s] = 0;

	dijkstra(n, ismeretlen, d, a, p);
	
	return 0;
}
