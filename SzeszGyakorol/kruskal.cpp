/*
 * Kisgyörgy Zoltán, 532
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void kruszkal(int n, int m, vector<pair<pair<int, int>, int>>& elek, vector<pair<pair<int, int>, int>>& feszitofa, int &koltseg)
{
	sort(elek.begin(), elek.end(), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) { return a.second < b.second;});
	vector<int> komp(n + 1);
	for (int i = 1; i <= n; i++)
	{
		komp[i] = i;
	}
	int i = 0, j = 0;
	while (j < m && i < n)
	{
		if (komp[elek[j].first.first] != komp[elek[j].first.second])
		{
			i++;
			feszitofa.push_back(elek[j]);
			koltseg += elek[j].second;
			int id = komp[elek[j].first.second];
			for (int k = 1; k <= n; k++)
			{
				if (komp[k] == id)
				{
					komp[k] = komp[elek[j].first.first];
				}
			}
		}
		j++;
	}
}

int main()
{
	int n, m, koltseg = 0;
	cin >> n >> m;
	vector<pair<pair<int, int>, int>> elek, feszitofa;
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		elek.push_back(make_pair(make_pair(u, v), w));
	}
	kruszkal(n, m, elek, feszitofa, koltseg);
	cout << "A feszitofa:" << endl;
	for (auto el:feszitofa)
	{
		cout << el.first.first << "-" << el.first.second << " : " << el.second << endl;
	}
	cout << "Koltseg: " << koltseg;
	return 0;
}
