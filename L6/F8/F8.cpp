/*
 * Kisgyörgy Zoltán, 532
 * L6-8 Szeptember 15-én az iskola igazgatója felkéri az első osztályos gyermekeket,
hogy forduljanak arccal felé, majd abból a célból, hogy felvezethesse őket az
osztálytermekbe, kiadja a parancsot: “Balra át!”. A gyermekek bizonytalanok.
Van, aki balra fordul, van, aki jobbra. Aki szemben találja magát a mellette
állóval, azt hiszi, hogy rosszul fordult és egy időegység alatt egyszer sarkon
fordul. Adott egy bizonyos kezdeti konfiguráció, amely a “Balra át!” parancs
után alakult ki. Állapítsuk meg, hány időegység alatt „nyugszik meg” a sor.
 */
#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

void vag(string& diakok, int db)
{
	int b = 0, j = db - 1;
	// bal oldali b-k levágása
	while (diakok[b] == 'b')
	{
		b++;
	}
	while (diakok[j] == 'j')
	{
		j--;
	}
	diakok = diakok.substr(b, db - b - (db - j - 1));
}

unsigned long long balra(string diakok, int db)
{
	unsigned long long it = 0;
	bool voltCsere = true;
	vector<pair<int, int>> csere;
	while (true)
	{
		vag(diakok, db);
		voltCsere = false;
		for (int i = 0; i <= db - 1; i++)
		{
			if (diakok[i] == 'j' && diakok[i + 1] == 'b')
			{
				csere.push_back(make_pair(i, i + 1));
				voltCsere = true;
			}
		}

		// ugyanabban az időegységben megfordulnak
		for (pair<int, int> p : csere)
		{
			diakok[p.first] = 'b';
			diakok[p.second] = 'j';
		}
		csere.clear();

		// ha nem volt csere, akkor vége
		if (!voltCsere)
			break;

		it++;
	}
	return it;
}

int main()
{
	string diakok;
	cin >> diakok;
	int db = diakok.length();
	cout << balra(diakok, db) << endl;

	return 0;
}
