/*
 * Kisgyörgy Zoltán, 532
 * L6-5 Adva van 𝑛 + 1 cipősdoboz és 𝑛 pár cipő, amelyek meg vannak számozva 1-től
𝑛-ig. Az 𝑛 pár cipő 𝑛 + 1 dobozban található, a dobozok közül az egyik üres. El
kell rendezni a cipőket úgy, hogy minden cipő a saját dobozába kerüljön és az üres
doboz a sor végére. Munka közben csak egy pár cipőt szabad kivenni a dobozból,
amelyben található, és azonnal be kell tenni az üres dobozba. Állapítsuk meg a
költöztetések sorozatát minimális számú művelettel
 */
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int keres(vector<int>& melyikDobozban, int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (melyikDobozban[i] != i)
		{
			return i;
		}
	}
	return -1;
}

void cipok(int n, vector<int>& ciposDobozok, vector<pair<int, int>>& lepesek)
{
	int nullasIndex = -1, k;
	vector<int> melyikDobozban(n + 2); // melyik dobozban van i . cipo most
	for (int i = 1; i <= n + 1; i++)
	{
		if (ciposDobozok[i] == 0)
		{
			nullasIndex = i;
		}
		else
		{
			melyikDobozban[ciposDobozok[i]] = i;
		}
	}
	
	while (true)
	{
		if (nullasIndex != n + 1) // ha nem az utolo a nullas
		{
			k = nullasIndex; // k a nullas indexe, ahova a cipőt kell tenni

			ciposDobozok[melyikDobozban[k]] = 0; // kiveszuk a k. cipot onnan, ahol van
			ciposDobozok[nullasIndex] = k; // betesszuk a k.-ba a cipot
			nullasIndex = melyikDobozban[k]; // az ures doboz indexe az eddigi k. indexe
			melyikDobozban[k] = k; // a k. dobozban a k. cipő van, azaz a helyén van
			lepesek.push_back(make_pair(nullasIndex, k));
		}
		else // ha az utolso a nullas
		{
			k = keres(melyikDobozban, n); // index amelyik dobozban nem a helyén van a cipő
			if (k == -1) return; // ha nincs ilyen, akkor kesz

			lepesek.push_back(make_pair(k, nullasIndex));
			ciposDobozok[nullasIndex] = ciposDobozok[k]; // átrakjuk a cipot az utolso helyre
			melyikDobozban[ciposDobozok[k]] = nullasIndex; // a cipo most az utolso helyen van
			nullasIndex = k; // az ures doboz indexe az eddigi k. indexe
			ciposDobozok[k] = 0; // 0 kerül a helyére ahol eddig a cipő volt
		}
	}
}

void kiir(vector<pair<int, int>>& lepesek)
{
	int m = lepesek.size();
	cout << m << endl;
	for (int i = 0; i < m; ++i)
	{
		cout << lepesek[i].first << " " << lepesek[i].second << endl;
	}
}

void beolvas(int &n, vector<int>& v)
{
	cin >> n;
	v.resize(n + 2);
	for (int i = 1; i <= n + 1; ++i)
	{
		cin >> v[i];
	}
}

int main()
{
	int n;
	vector<int> v;
	vector<pair<int, int>> lepesek;
	beolvas(n, v);
	cipok(n, v, lepesek);
	kiir(lepesek);

	return 0;
}
