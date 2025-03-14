/*
 * Kisgyörgy Zoltán, 532
 * L6-2 Egy falu főútcáján 𝑛 lakos él, minden két egymás melletti ház között
ugyanakkora a távolság. A falu jó bortermő vidéken található, így a lakók
szívesen fogyasztanak, de adnak is el bort. Érdekes módon a falun belül a
kereslet és a kínálat mindig egyenlő. Tudván, hogy két egymás melletti ház
között szállítani egy liter bort mindig egy egységnyi munkába kerül és ismervén,
hogy melyik lakos hány liter bort szeretne eladni vagy vásárolni, határozzuk
meg a minimális munkamennyiséget, amely szükséges ahhoz, hogy minden lakos
igénye ki legyen elégítve.

 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long boros(vector<int>& v)
{
	long long dblepes = 0, n = v.size(), kulonbseg = 0;

	for (int i = 0; i < n; i++)
	{
		kulonbseg += v[i];
		dblepes += abs(kulonbseg);
	}

	return dblepes;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	cout << boros(v);

	return 0;
}
