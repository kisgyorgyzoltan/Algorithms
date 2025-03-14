/*
 * Kisgyörgy Zoltán, 532
 * L5-7 .....Határozzuk meg a 𝑘 testvér életkorát!
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

void kiir(vector<int> eletkorok)
{
	for (int i = 0; i < eletkorok.size(); i++)
	{
		cout << eletkorok[i] << " ";
	}
	cout << endl;
}

bool teljesulIker(vector<int>& eletkorok)
{
	return eletkorok[0] == eletkorok[1];
}

void backtrack(
	int i,
	int n,
	int k,
	int dbOszto,
	vector<int>& osztok,
	vector<int>& eletkorok,
	unordered_map<int, vector<int>>& osszegEsVektorok,
	int szorzat,
	int osszeg,
	bool & talalt
)
{
	if (eletkorok.size() == k && szorzat == n)
	{
			if (osszegEsVektorok[osszeg].size() == 0)
			{
				osszegEsVektorok[osszeg] = eletkorok;
			}
			else
			{
				if (teljesulIker(osszegEsVektorok[osszeg]))
				{
					kiir(osszegEsVektorok[osszeg]);
					talalt = true;
					exit(0);
				}
				else if (teljesulIker(eletkorok))
				{
					kiir(eletkorok);
					talalt = true;
					exit(0);
				}
			}
		
	}
	else if (szorzat < n && eletkorok.size() < k)
	{
		for (; i < dbOszto; i++) // nem szigorúan növekvő sorrendben de növekvő sorrendben veszem ki az osztókat
		{
			eletkorok.push_back(osztok[i]);
			backtrack(i, n, k, dbOszto, osztok, eletkorok, osszegEsVektorok, szorzat * osztok[i], osszeg + osztok[i], talalt);
			eletkorok.pop_back();
		}
	}
}

void osztoi(int n, vector<int>& osztok, double gyok)
{
	for (int i = 1; i <= gyok; i++)
	{
		if (n % i == 0)
		{
			osztok.push_back(i);
			if (i != n / i)
			{
				osztok.push_back(n / i);
			}
		}
	}
	sort(osztok.begin(), osztok.end());
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> eletkorok;

	double gyok = sqrt(n);
	vector <int> osztok;
	osztoi(n, osztok, gyok);

	// eltároljuk az összegeket és 1 db vektort amelyiknek az összege az adott szám
	unordered_map<int, vector<int>> osszegEsVektorok;

	bool talalt = false;

	backtrack(0, n, k, osztok.size(), osztok, eletkorok, osszegEsVektorok, 1, 0, talalt);
	if (!talalt && osszegEsVektorok.size() > 0) // ha nem találtunk
	{
			vector<vector<int>> megoldasok; // kiszűrjük azokat amelyek teljesítik az ikerszám tulajdonságot
			for (auto it = osszegEsVektorok.begin(); it != osszegEsVektorok.end(); it++)
			{
				if (teljesulIker(it->second))
				{
					megoldasok.push_back(it->second);
				}
			}
			if (megoldasok.size() == 1) // csak akkor van egyértelmű megoldás ha csak egy ilyen van
			{
				kiir(megoldasok[0]);
			}
	}

	return 0;
}
