/*
 * Kisgyörgy Zoltán, 532
 * L7-8 Egy kiállítási csarnokot le fognak fedni előre gyártott műanyaglapokkal. Előbb
felosztották a csarnok alapját négyzet alakú felületekre úgy, hogy a csarnok
belsejében található oszlop pontosan egy ilyen négyzetnyi helyet foglaljon el.
A műanyaglapok három ilyen négyzetet fednek le L-alakban. A tervező rájött,
hogy nem fogja tudni ezekkel lefedni a teljes felületet, ezért kiválasztott egy
2
𝑛 × 2
𝑛 méretű részt a csarnokból, amelyen ott van az oszlop is. Tervezzük meg
a lefedést felhasználva az alakzatot úgy, hogy ne maradjon fedetlen felület a
kiválasztott részben. Ezen alakzat elforgatható három irányba.

 */

#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <utility>
#include <algorithm>

using namespace std;

typedef tuple<pair<int, int>, pair<int, int>, pair<int, int>> Lap;

Lap makeLap(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
{
	if (p1.first > p2.first)
	{
		swap(p1, p2);
	}
	else if (p1.first == p2.first && p1.second > p2.second)
	{
		swap(p1, p2);
	}

	if (p1.first > p3.first)
	{
		swap(p1, p3);
	}
	else if (p1.first == p3.first && p1.second > p3.second)
	{
		swap(p1, p3);
	}

	if (p2.first > p3.first)
	{
		swap(p2, p3);
	}
	else if (p2.first == p3.first && p2.second > p3.second)
	{
		swap(p2, p3);
	}
	return make_tuple(p1, p2, p3);
}

void lerak(int x1, int y1, int x2, int y2, int x3, int y3, vector<vector<int>>& v, int& db, vector<Lap>& lapPoz)
{
	db++;
	v[x1][y1] = db;
	v[x2][y2] = db;
	v[x3][y3] = db;
	lapPoz.push_back(makeLap(make_pair(x1, y1), make_pair(x2, y2), make_pair(x3, y3)));
}

int lapok(int n, int x, int y, int &db, vector<vector<int>>& v, vector<Lap>& lapPoz)
{
	int sor = -1, oszlop = -1;
	if (n == 2)
	{
		int x1 = -1, y1 = -1, x2 = -1, y2 = -1, x3 = -1, y3 = -1;
		db++;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (v[x+ i][y + j] == 0)
				{
					v[x + i][y + j] = db;
					x1 == -1 ? x1 = x + i, y1 = y + j : 
					x2 == -1 ? x2 = x + i, y2 = y + j : 
					x3 == -1 ? x3 = x + i, y3 = y + j : 0;
				}
			}
		}
		if (x1 != -1 && x2 != -1 && x3 != -1)
		{
			lapPoz.push_back(makeLap(make_pair(x1, y1), make_pair(x2, y2), make_pair(x3, y3)));
		}
		return 0;
	}

	// megkeresem az oszlopot
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (v[i][j] != 0)
			{
				sor = i;
				oszlop = j;
			}
		}
	}

	if (sor < x + n / 2 && oszlop < y + n / 2) // 1. negyed
	{
		lerak(x + n / 2, y + (n / 2) - 1, x + n / 2, y + n / 2, x + n / 2 - 1, y + n / 2, v, db, lapPoz);
	}
	else if (sor >= x + n / 2 && oszlop < y + n / 2) // 3. negyed
	{
		lerak(x + (n / 2) - 1, y + (n / 2), x + (n / 2), y + n / 2, x + (n / 2) - 1, y + (n / 2) - 1, v, db, lapPoz);
	}
	else if (sor < x + n / 2 && oszlop >= y + n / 2) // 2. negyed
	{
		lerak(x + n / 2, y + (n / 2) - 1, x + n / 2, y + n / 2, x + n / 2 - 1, y + n / 2 - 1, v, db, lapPoz);
	}
	else if (sor >= x + n / 2 && oszlop >= y + n / 2) // 4. negyed
	{
		lerak(x + (n / 2) - 1, y + (n / 2), x + (n / 2), y + (n / 2) - 1, x + (n / 2) - 1, y + (n / 2) - 1, v, db, lapPoz);
	}

	// felosztas 4 negyedre
	lapok(n / 2, x, y + n / 2, db, v, lapPoz);
	lapok(n / 2, x, y, db, v, lapPoz);
	lapok(n / 2, x + n / 2, y, db, v, lapPoz);
	lapok(n / 2, x + n / 2, y + n / 2, db, v, lapPoz);

	return 0;
}

void beolvas(int& n, vector<vector<int>>& v)
{
	int k, oszlopX, oszlopY;
	cin >> k >> oszlopX >> oszlopY;
	oszlopX--;
	oszlopY--;
	n = pow(2, k);
	v = vector<vector<int>>(n, vector<int>(n, 0));
	v[oszlopX][oszlopY] = -1;
}

void rendez(vector<Lap>& lapPoz)
{
	sort(lapPoz.begin(), lapPoz.end(), [](Lap l1, Lap l2) {return (get<0>(l1).first == get<0>(l2).first ? get<0>(l1).second < get<0>(l2).second : get<0>(l1).first < get<0>(l2).first); });
}

void kiir(vector<Lap>& lapPoz)
{
	for (Lap l : lapPoz)
	{
		cout << get<0>(l).first + 1 << " " << get<0>(l).second + 1 << " " << get<1>(l).first + 1 << " " << get<1>(l).second + 1 << " " << get<2>(l).first + 1 << " " << get<2>(l).second + 1 << endl;
	}
}

int main()
{
	int n, db = 0;
	vector<vector<int>> v;
	vector<Lap> lapPoz;
	beolvas(n, v);
	lapok(n, 0, 0, db, v, lapPoz);
	rendez(lapPoz);
	kiir(lapPoz);
	return 0;
}
