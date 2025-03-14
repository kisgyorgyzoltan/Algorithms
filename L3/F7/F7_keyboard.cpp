/*
 * Kisgyörgy Zoltán, 532
 * L3 - 7. Határozzuk meg két szám összegét!
 */

#include <iostream>
#include <cstring>

using namespace std;

void beolvas(char *&szam1, char *&szam2, int &hossz1, int &hossz2)
{

	cin >> hossz1;
	szam1 = new char[hossz1 + 1];
	cin >> szam1;

	cin >> hossz2;
	szam2 = new char[hossz2 + 1];
	cin >> szam2;
}

void reverse(char *&szam)
{
	int hossz = strlen(szam);
	int i = 0;
	int j = hossz - 1;

	while (i < j)
	{
		char temp = szam[i];
		szam[i] = szam[j];
		szam[j] = temp;

		i++;
		j--;
	}
}

void osszead(char *&szam1, char *&szam2, int &hossz1, int &hossz2)
{
	char *eredmeny = new char[hossz1 + hossz2 + 3];
	for (int i = 0; i < hossz1 + hossz2 + 3; i++)
	{
		eredmeny[i] = 0;
	}

	if (hossz1 > hossz2)
	{
		swap(szam1, szam2);
		swap(hossz1, hossz2);
	}

	// hátulról kezdem az összeadást
	reverse(szam1);
	reverse(szam2);

	int maradek = 0, db = 0;
	for (int i = 0; i < hossz1; i++)
	{
		int szamjegy1 = szam1[i] - '0', szamjegy2 = szam2[i] - '0';
		int osszeg = (szamjegy1 + szamjegy2 + maradek);
		char vege = osszeg % 10 + '0';
		eredmeny[db] = vege;
		db++;
		maradek = osszeg / 10;
	}

	// nagyobb szám maradék számjegyei
	for (int i = hossz1; i < hossz2; i++)
	{
		int szamjegy2 = szam2[i] - '0';
		int osszeg = (szamjegy2 + maradek);
		char vege = osszeg % 10 + '0';
		eredmeny[db] = vege;
		db++;

		maradek = osszeg / 10;
	}

	// 9-es(ek) eseten mehet tovabb
	if (maradek)
	{
		eredmeny[db] = maradek + '0';
		db++;
	}
	// visszafele olvasva megkapjuk az eredmenyt
	reverse(eredmeny);

	for (int i = 0; i < db; i++)
	{
		cout << eredmeny[i];
	}
	cout << endl;
	delete[] eredmeny;
}

int main()
{
	int hossz1, hossz2;
	char *szam1, *szam2;
	beolvas(szam1, szam2, hossz1, hossz2);

	osszead(szam1, szam2, hossz1, hossz2);

	delete[] szam1;
	delete[] szam2;
	return 0;
}