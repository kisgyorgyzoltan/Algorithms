/*
 * Kisgyörgy Zoltán, 532
 * L5-8 Adva van egy 𝑛 személyből álló csoport. Minden személynek van legalább 𝑛/2
barátja a csoporton belül. Lacinak van egy könyve, amelyet a csoport minden
tagja el szeretne olvasni. Írjátok ki, hogyan vándorol a könyv egyik személytől
a másikig úgy, hogy mindenkihez csak egyszer kerül, és egy személy csak egy
barátjának kölcsönzi a könyvet, amíg az visszatér Lacihoz. Az összes lehetséges
megoldást keressük, a megoldásokat tetszőleges sorrendben ki lehet íratni.
 */

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

void kiir(vector<string> ut)
{
	for (unsigned i = 0; i < ut.size(); ++i)
	{
		cout << ut[i] << " ";
	}
	cout << endl;
}

void backtrack(string jelenlegi, vector<pair<string, string>> baratParok, vector<string> ut, unordered_map <string, bool> voltNala, string laci, unsigned n)
{
	if (ut.size() == n + 1 && ut[ut.size() - 1] == laci)
	{
		kiir(ut);
	}
	else
	{
		for (unsigned i = 0; i < baratParok.size(); ++i)
		{
			if (baratParok[i].first == jelenlegi && !voltNala[baratParok[i].second]) // ha a jelenlegi személy barátjánál még nem járt
			{
				ut.push_back(baratParok[i].second);
				voltNala[baratParok[i].second] = true;
				backtrack(baratParok[i].second, baratParok, ut, voltNala, laci, n);
				ut.pop_back();
				voltNala[baratParok[i].second] = false;
			}
			else if (baratParok[i].second == jelenlegi && !voltNala[baratParok[i].first]) // ha a jelenlegi személy barátjánál még nem járt (fordított sorrendben)
			{
				ut.push_back(baratParok[i].first);
				voltNala[baratParok[i].first] = true;
				backtrack(baratParok[i].first, baratParok, ut, voltNala, laci, n);
				ut.pop_back();
				voltNala[baratParok[i].first] = false;
			}
		}
	}
}

int main()
{
	unsigned n, m;
	cin >> n >> m;
	string laci = "Laci";
	vector<pair<string, string>> baratParok;
	vector<string> ut;
	unordered_map <string, bool> voltNala;
	for (unsigned i = 0; i < m; ++i)
	{
		string a, b;
		cin >> a >> b;
		baratParok.push_back(make_pair(a, b));
		voltNala[a] = false;
		voltNala[b] = false;
	}
	ut.push_back(laci);
	backtrack(laci, baratParok, ut, voltNala, laci, n);

	return 0;
}
