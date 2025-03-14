/*
 * Kisgyörgy Zoltán, 532
 * L6-4 A háború során 𝑚 különböző helyen kell őrt állni, mindegyik helyről tudjuk,
hogy melyik nap kezdetétől melyik nap végéig kell ott szolgálatot teljesítsen egy
katona. Állapítsuk meg, hogy elegendő-e 𝑛 darab katona ahhoz, hogy őrt álljunk
mind az 𝑚 helyen!
 */

#include <iostream>
#include <map>

using namespace std;

void katonak(int n, int m , map<int, int> &s, map<int, int> &e)
{
	if (n <= 1  && m <= 0)
	{
		cout << "igen" << endl;
	}
	else
	{
		int maxVege = e.rbegin()->first;
		for (int i = 1; i <= maxVege; i++)
		{
			if (s[i])
			{
				if (n == 0 || n - s[i] < 0) // nem lehet 0-nál kevesebb katona és nem kerülhetünk negatívba a katonák
				{
					cout << "nem" << endl;
					return;
				}
				else
				{
					n-=s[i];
				}	
			}
			if (e[i])
			{
				n += e[i];
			}
		}
		if (n >= 0)
		{
			cout << "igen" << endl;
		}
		else
		{
			cout << "nem" << endl;
		}
	}
}

void beolvas(int &n, int &m, map<int, int> &s, map<int, int> &e)
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		s[a]++;
		e[b]++;
	}
}

int main()
{
	int n, m;
	map<int, int> s, e;
	beolvas(n, m, s, e);
	katonak(n, m, s, e);
	
	return 0;
}
