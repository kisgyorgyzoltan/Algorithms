/*
 * Kisgyörgy Zoltán, 532
 * L6-6 Az Encián motelben évekkel előre is fogadnak foglalásokat az odaérkező
𝑛 turistacsoport számára. Ismervén a napot, amellyel kezdve foglalni lehet
és amelyet 1-el számozunk, a csoportok megjelölik az első és az utolsó napot,
amelyet a motelben szeretnének tölteni. Az Encián tulajdonosa mindegyik
csoport számára szeretne egy tradicionális előadást szervezni, amire csak a motel
dísztermében kerülhet sor, ahova egyszerre csak egy turistacsoport fér be. Ezeken
az előadásokon fel fog lépni egy előadó, aki megszabja azt az 𝑛 napot, amikor
el tud jönni az előadásokra. Segítsetek a tulajdonosnak eldönteni, hogy melyik
turistacsoportnak melyik napra szervezze meg az előadást.
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <algorithm>

using namespace std;

void beolvas(int &n, vector<tuple<int,int,int>> &igenyelt, vector<pair<int, int>> &eloado, vector<pair<int, int>> &megoldas)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		igenyelt.push_back(make_tuple(a, b, i)); // a, b, eredetiIndex
	}
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		eloado.push_back(make_pair(a, i));
	}
	megoldas.resize(n);
}

void turistak(int n, vector<tuple<int, int, int>>& igenyelt, vector<pair<int, int>>& eloado, vector<pair<int, int>>& megoldas, bool& mindenkinekJo)
{
	mindenkinekJo = true; // feltetelezzuk, hogy mindenkinek lesz jo idopont

	sort(eloado.begin(), eloado.end(), [](pair<int, int> a, pair<int, int> b) {return a.first < b.first; }); // novekvo sorrendbe rendezzuk az eloado napjait
	sort(igenyelt.begin(), igenyelt.end(), [](tuple<int, int, int> a, tuple<int, int, int> b) {return get<1>(a) < get<1>(b); }); // novekvo sorrendbe rendezzuk a turistak igenyeit a befejezesi napjuk szerint

	for (int j = 0; j < n; j++) // vegigmegyunk az eloado napjain
	{
		int eloadasNap = eloado[j].first; // a j. eloadas napja
		int eloadasIndex = eloado[j].second; // a j. eloadas eredeti indexe
		bool vanJoIdopont = false; // feltetelezzuk, hogy nincs jo idopont

		for (int i = 0; i < n; i++) // vegigmegyunk a turista csoportokon
		{
			int elsoNap = get<0>(igenyelt[i]),
				utolsoNap = get<1>(igenyelt[i]),
				eredetiIndex = get<2>(igenyelt[i]); // a turista igenyei

			if (elsoNap <= eloadasNap && eloadasNap <= utolsoNap) // ha a turistacsoport igenyei kozott van az eloado napja
			{
				megoldas[j] = make_pair(eredetiIndex + 1, eloadasIndex + 1);
				igenyelt.erase(igenyelt.begin() + i); // toroljuk a turistacsoportot a listabol
				vanJoIdopont = true; // jelezzuk, hogy van jo idopont
				break; // kilepunk a ciklusbol
			}
		}

		if (!vanJoIdopont) // ha nincs jo idopont
		{
			mindenkinekJo = false; // akkor nem mindenkinek jo
			break; // kilepunk a ciklusbol
		}
	}
}

int main()
{
	int n;
	bool mindenkinekJo = true;
	vector<tuple<int, int, int>> igenyelt;
	vector<pair<int, int>> megoldas,eloado;
	beolvas(n, igenyelt, eloado, megoldas);
	turistak(n, igenyelt, eloado, megoldas, mindenkinekJo);

	if (mindenkinekJo)
	{
		for (pair<int, int> i : megoldas)
		{
			cout << i.first << " " << i.second << endl;
		}
	}
	else
	{
		cout << 0 << " " << 0 << endl;
	}

	return 0;
}
