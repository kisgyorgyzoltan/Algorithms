/*
 * Kisgyörgy Zoltán, 532
 * L7-6 Adott egy 𝑛 elemű tömb, mely 32 bites előjeles egész számokat tartalmaz
és egy 𝑥 32 bites előjeles egész szám. Határozzuk meg, hogy létezik-e két olyan
eleme a tömbnek, melyek összege pontosan 𝑥. Alkalmazzunk bináris keresést!
 */

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>

using namespace std;

void beolvas(map<long, vector<pair<long, int>>>& m, int& n, long& x)
{
	cin >> n;
	cin >> x;
	long s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		m[s].push_back(make_pair(s, i + 1));
	}
}

pair<long, int> binKeres(map<long, vector<pair<long, int>>>& m, long x, long bal, long jobb, bool& talalt, int index)
{
	if (bal <= jobb)
	{
		long kozep = (bal + jobb) / 2;
		if (kozep == x)
		{
			pair <long, int> par;
			unsigned long i = 0;
			while (i < m[kozep].size() && m[kozep][i].second == index)
			{
				i++;
			}
			if (i < m[kozep].size())
			{
				talalt = true;
				par = m[kozep][i];
				return par;
			}
			else
			{
				talalt = false;
				return make_pair(0, 0);
			}
		}
		else if (kozep < x)
		{
			return binKeres(m, x, kozep + 1, jobb, talalt, index);
		}
		else
		{
			return binKeres(m, x, bal, kozep - 1, talalt, index);
		}
	}
	else
	{
		talalt = false;
		return make_pair(0, 0);
	}
}

void keres(map<long, vector<pair<long, int>>>& m, int& n, long& x)
{
	map<long, vector<pair<long, int>>> rendezett = m;
	for (auto& i : rendezett)
	{
		sort(i.second.begin(), i.second.end(), [](pair<long, int> a, pair<long, int> b) {return a.second < b.second; });
	}

	bool talalt = false;
	pair<long, int> par;
	for (auto& i : rendezett)
	{
		long elso = i.first;
		long masodik = x - elso;
		par = binKeres(m, masodik, m.begin()->first, m.rbegin()->first, talalt, i.second[0].second);
		if (talalt)
		{
			cout << 1 << endl;
			if (par.second < i.second[0].second)
				cout << par.second << " " << i.second[0].second << endl;
			else
				cout << i.second[0].second << " " << par.second << endl;
			return;
		}
	}
	cout << 0 << endl;
}

int main()
{
	int n;
	long x;
	map<long, vector<pair<long, int>>> m;
	beolvas(m, n, x);
	keres(m, n, x);

	return 0;
}