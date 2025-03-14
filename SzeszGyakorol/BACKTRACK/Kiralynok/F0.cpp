/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>

using namespace std;

void kiir(vector<int>& v)
{
	int n = v.size() - 1;
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

bool benneVan(vector<int>& sorszamok, int a)
{
	for (int i : sorszamok)
	{
		if (i == a)
		{
			return true;
		}
	}
	return false;
}

void kiralnyok(int k, int n, int q, int& db, int& mentve, vector<int>& v, vector<int>& sorszamok, vector<bool>& sor, vector<bool>& atlok,
	vector<bool>& mellekatlok, vector<vector<int>>& megoldasok)
{
	if (k <= n)
	{
		int atl, matl;
		for (int i = 1; i <= n; i++)
		{
			v[k] = i;
			atl = i - k + n;
			matl = i + k;
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
		if (mentve <= q && benneVan(sorszamok, db))
		{
			mentve++;
			megoldasok[mentve] = v;
		}
	}
}

int main()
{
	int n, q, db = 0, mentve = 0;
	cin >> n >> q;
	vector<vector<int>> megoldasok(q + 1);
	vector<bool> sor(n + 1, false), atlok(2 * n + 1, false), mellekatlok(2 * n + 1, false);
	vector<int> v(n + 1), sorszamok(q + 1);
	for (int i = 1; i <= q; i++)
	{
		cin >> sorszamok[i];
	}
	kiralnyok(1, n, q, db, mentve, v, sorszamok, sor, atlok, mellekatlok, megoldasok);
	for (int i = 1; i <= q; i++)
	{
		cout << sorszamok[i] << endl;
		kiir(megoldasok[i]);
	}
	cout << endl << db;

	return 0;
}
