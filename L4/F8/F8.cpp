/*
 * Kisgyörgy Zoltán, 532
	L4-8 Írjunk rekurzív algoritmust, amely átalakít egy, a 16-os számrendszerben
	megadott egész számot a 10-es számrendszerbe! Ne használjunk ismétlő struktúrát a beolvasáson kívül!
 */

#include <iostream>
#include <cctype>

using namespace std;

short szamjegy(char c)
{
	c = toupper(c);

	int szj;
	if (c >= '0' && c <= '9') {
		szj = c - '0';
	}
	else if (c >= 'A' && c <= 'F') {
		szj = c - 'A' + 10;
	}
	else {
		szj = -1;
	}

	return szj;
}

unsigned long long atalakit(int n, char*& hexa, bool& hiba)
{
	if (n == 0)
	{
		return 0;
	}

	short uszjegy = szamjegy(hexa[n - 1]);
	if (uszjegy == -1)
	{
		hiba = true;
		return 0;
	}

	return atalakit(n - 1, hexa, hiba) * 16 + uszjegy;
}

void beolvas(int& n, char*& hexa)
{
	cin >> n;
	hexa = new char[n + 1];
	for (int i = 0; i < n; i++)
	{
		cin >> hexa[i];
	}
}

int main()
{
	int n = -1;
	char* hexa = nullptr;
	bool hiba = false;
	beolvas(n, hexa);

	if (n > 16)
	{
		cout << -1;
	}
	else
	{
		unsigned long long eredmeny = atalakit(n, hexa, hiba);
		if (hiba)
		{
			cout << -1;
		}
		else
		{
			cout << eredmeny;
		}
	}

	delete[] hexa;

	return 0;
}
