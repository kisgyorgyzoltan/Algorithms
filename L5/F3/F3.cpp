/*
 * Kisgyörgy Zoltán, 532
 * L5-3 Adva van egy 𝑛 darab egész számot tartalmazó sorozat. Helyezzünk az
adott számok közé 𝑛 − 1 aritmetikai műveleti jelet a (+, −, *, /) halmazból, úgy,
hogy a kifejezés értéke legyen egyenlő egy adott 𝑥 számmal! A kifejezés értéke
minden lépésben legyen egész szám! A műveleteket nem a matematikából ismert
operátorprecedencia szerint végezzük, hanem megjelenésük sorrendjében
 */

#include <iostream>

using namespace std;

void beolvas(int& n, int& eredmeny, int*& a)
{

	cin >> n;
	a = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cin >> eredmeny;
}

bool ellenorzes(int n, int eredmeny, int* szamok, int* muvelet_index, char muvelet[], bool& talalt)
{
	int osszeg = szamok[1];
	for (int i = 1; i < n; i++)
	{
		if (muvelet_index[i] == 0) // 0 = +, 1 = -, 2 = *, 3 = /
		{
			osszeg += szamok[i + 1];
		}
		if (muvelet_index[i] == 1)
		{
			osszeg -= szamok[i + 1];
		}
		if (muvelet_index[i] == 2)
		{
			osszeg *= szamok[i + 1];
		}
		if (muvelet_index[i] == 3)
		{
			if (szamok[i + 1] != 0 && osszeg % szamok[i + 1] == 0)
			{
				osszeg /= szamok[i + 1];
			}
			else
			{
				return false;
			}
		}
	}

	if (osszeg == eredmeny)
	{
		talalt = true;
		return true;
	}
	return false;
}

void kiir(int n, int eredmeny, int* szamok, int* muvelet_index, char muvelet[], bool& talalt)
{
	cout << eredmeny << "=" << szamok[1];
	for (int i = 1; i < n; i++)
	{
		cout << muvelet[muvelet_index[i]] << szamok[i + 1];
	}
	cout << endl;
}
void general(int n, int k, int eredmeny, int* szamok, int* muvelet_index, char muvelet[], bool& talalt)
{
	for (int i = 0; i < 4; i++)
	{
		muvelet_index[k] = i;
		if (k == (n - 1)) // n - 1 darab muveletjel kell legyen
		{
			if (ellenorzes(n, eredmeny, szamok, muvelet_index, muvelet, talalt))
			{
				kiir(n, eredmeny, szamok, muvelet_index, muvelet, talalt);
			}
		}
		else

		{
			general(n, k + 1, eredmeny, szamok, muvelet_index, muvelet, talalt);
			if (k == 0) return; // azert hogy ne irja ki 4-szer a megoldasokat
		}
	}
}
int main()
{
	int* szamok, n, eredmeny, * muvelet_index;
	char muvelet[5] = "+-*/";
	bool talalt = false;
	beolvas(n, eredmeny, szamok);
	muvelet_index = new int[n];
	general(n, 0, eredmeny, szamok, muvelet_index, muvelet, talalt);
	if (!talalt)
	{
		cout << -1;
	}
	delete[] muvelet_index;
	delete[] szamok;
	return 0;
}