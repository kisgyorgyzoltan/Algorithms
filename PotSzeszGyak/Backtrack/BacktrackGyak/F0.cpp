/*
 * Kisgyörgy Zoltán, 532
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

const string LACI = "Laci";

void konyv(int k, string jelenlegi, int n, int m, vector<string> &ut, vector<pair<string, string>> &baratok, unordered_map<string, bool> &volt)
{
	if (k == n + 1 && ut[n] == LACI)
	{
		for (int i = 0; i < n + 1; i++)
		{
			cout << ut[i] << ' ';
		}
		cout << endl;
	}
	else
	{
		for (auto p:baratok)
		{
			if (p.first == jelenlegi && !volt[p.second])
			{
				volt[p.second] = true;
				ut.push_back(p.second);
				konyv(k + 1, p.second, n, m, ut, baratok, volt);
				ut.pop_back();
				volt[p.second] = false;
			}
			if (p.second == jelenlegi && !volt[p.first])
			{
				volt[p.first] = true;
				ut.push_back(p.first);
				konyv(k + 1, p.first, n, m, ut, baratok, volt);
				ut.pop_back();
				volt[p.first] = false;
			}
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> ut;
	vector<pair<string, string>> baratok;
	unordered_map<string, bool> volt;
	for (int i = 0; i < m; i++)
	{
		string a, b;
		cin >> a >> b;
		baratok.push_back(make_pair(a, b));
		volt[a] = false;
		volt[b] = false;
	}
	ut.push_back(LACI);

	konyv(1, LACI, n, m, ut, baratok, volt);

	return 0;
}
