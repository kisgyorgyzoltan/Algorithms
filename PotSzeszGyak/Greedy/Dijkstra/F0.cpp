/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>
#include <climits>

#define INF INT_MAX

using namespace std;

int dmin(int& ind, int n, vector<int>& d, vector<bool>& ismertetlen)
{
	int min = INF;
	for (int i = 0; i < n; i++)
	{
		if (ismertetlen[i])
		{
			if (min > d[i])
			{
				min = d[i];
				ind = i;
			}
		}
	}
	return min;
}

void dijkstra(int n, int m, vector<int> &d, vector<int>& p, vector<bool>& ismertetlen, vector<vector<int>>& a)
{
	int ind;
	while (dmin(ind, n, d, ismertetlen) < INF)
	{
		ismertetlen[ind] = false;
		for (int j = 0; j < n; j++)
		{
			if (ismertetlen[j] && a[ind][j] < INF)
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
	vector<int> d(n), p;
	vector<bool> ismeretlen(n);
	vector<vector<int>> a(n, vector<int>(n, INF));

	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[u][v] = w;
	}

	for (int i = 0; i < n; i++)
	{
		d[i] = a[s][i];
		p[i] = s;
		ismeretlen[i] = true;
	}
	d[s] = 0;
	ismeretlen[s] = false;

	dijkstra(n, m, d, p, ismeretlen, a);
	return 0;
}
