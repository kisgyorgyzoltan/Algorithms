/*
 * Kisgyörgy Zoltán, 532
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void kiir(vector<int>& v, int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j == v[i])
			{
				cout << "Q";
			}
			else
			{
				cout << ".";
			}
		}
		cout << endl;
	}
	cout << endl;
}

bool benneVan(vector<int>& sorszamok, int a, int q)
{
	for (int i = 1; i <= q; i++)
	{
		if (sorszamok[i] == a)
		{
			return true;
		}
	}
	return false;
}

void kiralnyok(int k, int n, int q, int& db, int& mentve, vector<int>& v, vector<int>& sorszamok, vector<bool>& sor, vector<bool>& atlok,
	vector<bool>& mellekatlok, unordered_map<int, vector<int>> &megoldasok)
{
	if (k <= n)
	{
		int atl, matl;
		for (int i = 1; i <= n; i++)
		{
			v[k] = i;
			atl = i - k + n + 1;
			matl = i + k + 1;

			if (!sor[i] && !atlok[atl] && !mellekatlok[matl])
			{
				sor[i] = true;
				atlok[atl] = true;
				mellekatlok[matl] = true;
				kiralnyok(k + 1, n, q, db, mentve, v, sorszamok, sor, atlok, mellekatlok, megoldasok);
				sor[i] = false;
				atlok[atl] = false;
				mellekatlok[matl] = false;
			}
		}
	}
	else
	{
		db++;
		if (mentve <= q && benneVan(sorszamok, db, q))
		{
			mentve++;
			megoldasok[db] = v;
		}
	}
}

int main()
{
	int n, q, db = 0, mentve = 0;
	cin >> n >> q;
	unordered_map<int, vector<int>> megoldasok;
	vector<bool> sor(n + 1, false), atlok(2 * n + 2, false), mellekatlok(2 * n + 2, false);
	vector<int> v(n + 1, 0), sorszamok(q + 1);
	for (int i = 1; i <= q; i++)
	{
		cin >> sorszamok[i];
	}
	kiralnyok(1, n, q, db, mentve, v, sorszamok, sor, atlok, mellekatlok, megoldasok);
	if (mentve > 0)
	{
		for (int i = 1; i <= q; i++)
		{
			kiir(megoldasok[sorszamok[i]], n);
		}
	}
	
	cout << db;

	return 0;
}
