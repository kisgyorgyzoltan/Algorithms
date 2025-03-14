/*
 * Kisgyörgy Zoltán, 532
 * L5-1. Generáljunk minden lehetséges sorozatot, amelynek elemei a 0, 1, 2 halmazból
vannak, és a 0 𝑚-szer, az 1 𝑝-szer és a 2 𝑞-szor fordul elő.
 */

#include <iostream>

using namespace std;

bool helyes(int a)
{
	return (a >= 0 && a <= 4);
}

void beolvas(int mpq[3])
{
	cin >> mpq[0] >> mpq[1] >> mpq[2];
}

void kiir(int* megoldas, int s)
{
	for (int i = 0; i < s; i++)
	{
		cout << megoldas[i] << " ";
	}
	cout << endl;
}

void backtrack(int mpq[3], int megoldas[3], int i, int s)
{
	if (i == s)
	{
		kiir(megoldas, s);
	}
	else
	{
		for (int j = 0;j < 3;j++)
		{
			if (mpq[j] > 0)
			{
				megoldas[i] = j;
				mpq[j]--;
				backtrack(mpq, megoldas, i + 1, s);
				mpq[j]++;
			}
		}
	}
}

int main()
{
	int mpq[3];
	int* megoldas;
	beolvas(mpq);
	int s = mpq[0] + mpq[1] + mpq[2];
	megoldas = new int[s];
	if (helyes(mpq[0]) && helyes(mpq[1]) && helyes(mpq[2]))
	{
		backtrack(mpq, megoldas, 0, s);
	}
	delete[]megoldas;
	return 0;
}
