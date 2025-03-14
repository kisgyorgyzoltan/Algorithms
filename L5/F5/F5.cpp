/*
 * Kisgyörgy Zoltán, 532
 * L5-5 Határozzuk meg 𝑛 darab természetes szám osztóinak halmazát!
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

const auto MAX = 100000000000000;
const auto sqrtMax = sqrt(MAX);


void kiir(set<unsigned long long>& v)
{
	cout << v.size() << endl;
	for (auto i = v.begin(); i != v.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

void osztokBacktrack(unsigned long long szam, vector <unsigned long long>& primek, int i, set<unsigned long long> v, double gyok, int dbPrim);

void backtrackSeged(unsigned long long szam, unsigned long long oszto, unsigned long long eredeti, vector <unsigned long long>& primek, set<unsigned long long>& v, int i, double gyok, int dbPrim)
{
	if (oszto <= szam)
	{
		if (szam % oszto == 0)
		{
			if (szam / oszto != oszto)
			{
				v.insert(oszto);
				v.insert(szam / oszto);
				backtrackSeged(szam, oszto * eredeti, eredeti, primek, v, i, gyok, dbPrim);
				v.erase(szam / oszto);
				v.erase(oszto);
			}
			else
			{
				v.insert(oszto);
				backtrackSeged(szam, oszto * eredeti, eredeti, primek, v, i, gyok, dbPrim);
				v.erase(oszto);
			}
		}
		else
		{
			backtrackSeged(szam, oszto * eredeti, eredeti, primek, v, i, gyok, dbPrim);
		}
	}
	else
	{
		osztokBacktrack(szam, primek, i + 1, v, gyok, dbPrim);
	}
}

void osztokBacktrack(unsigned long long szam, vector <unsigned long long>& primek, int i, set<unsigned long long> v, double gyok, int dbPrim)
{
	if (i < dbPrim && primek[i] <= gyok)
	{
		if (szam % primek[i] == 0)
		{
			backtrackSeged(szam, primek[i], primek[i], primek, v, i, gyok, dbPrim);
		}
		else
		{
			osztokBacktrack(szam, primek, i + 1, v, gyok, dbPrim);
		}
	}
	else
	{
		v.insert(szam);
		kiir(v);
		v.erase(szam);
	}
}

void osztok(int n, vector<unsigned long long>& szamok, vector<unsigned long long>& primek)
{
	set<unsigned long long> v;
	v.insert(1);
	for (int i = 1; i <= n; i++)
	{
		double gyok = sqrt(szamok[i]);
		int kerekitettGyok = static_cast<int>(gyok);

		unsigned long long oszto = 10;
		if (szamok[i] % oszto == 0 && szamok[i] > 0)
		{
			unsigned long long szam = szamok[i];
			while (szam > 0 && szam % oszto == 0)
			{
				v.insert(oszto);
				if (szam / oszto != oszto)
				{
					v.insert(szam / oszto);
				}
				szam /= oszto;
			}
		}


		if (kerekitettGyok * kerekitettGyok == szamok[i])
		{
			v.insert(kerekitettGyok);
			osztokBacktrack(szamok[i], primek, 0, v, gyok, primek.size());
			v.erase(kerekitettGyok);
		}
		else
		{
			osztokBacktrack(szamok[i], primek, 0, v, gyok, primek.size());
		}
	}
}

unsigned long long maximum(vector<unsigned long long>& v)
{
	unsigned long long max = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] > max)
		{
			max = v[i];
		}
	}
	return max;
}

void szita(vector<bool>& prim)
{
	prim[0] = false;
	prim[1] = false;
	int n = prim.size();
	for (int i = 2; i < n; i++)
	{
		if (prim[i])
		{
			for (int j = i * i; j < prim.size(); j += i)
			{
				prim[j] = false;
			}
		}
	}
}

void kiveszPrimek(vector<bool>& primSzita, vector<unsigned long long>& primek)
{
	for (int i = 0; i < primSzita.size(); i++)
	{
		if (primSzita[i])
		{
			primek.push_back(i);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector <unsigned long long> primek, szamok(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> szamok[i];
	}
	unsigned long long maxSzam = maximum(szamok);
	double gyokMaxSzam = sqrt(maxSzam);
	vector<bool> primSzita(gyokMaxSzam + 1, true);
	szita(primSzita);
	kiveszPrimek(primSzita, primek);
	osztok(n, szamok, primek);

	return 0;
}
