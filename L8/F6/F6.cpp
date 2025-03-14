/*
 * Kisgyörgy Zoltán, 532
 * L8-6 Adott egy 𝑛 karakterből álló mondat melyből hiányoznak a szóközök és egy
𝑚 szóból álló szótár. Bontsuk fel a mondatot minimális számú szóra
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void beolvas(int& n, int& m, vector<string>& szavak, string& mondat)
{
	cin >> n;
	cin >> mondat;
	cin >> m;
	string szo;
	for (int i = 0; i < m; i++)
	{
		cin >> szo;
		szavak.push_back(szo);
	}
}

void bont(vector<string>& szavak, string mondat, int n, int m)
{
	vector<int> megoldas(n+1, -1);
	megoldas[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		string szo = mondat.substr(0,i);
		
		for (int i = 0; i < szavak.size(); i++)
		{
			if (szo == szavak[i])
			{
				megoldas[i] = min(megoldas[i], megoldas[i-szo.size()] + 1);
			}
		}
	}

	cout << megoldas[n] - 1 << endl;
}
	

int main()
{
	vector<string> szavak;
	string mondat;
	int n, m;
	beolvas(n,m, szavak, mondat);
	bont(szavak, mondat, n, m);
	return 0;
}
