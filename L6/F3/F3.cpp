/*
 * Kisgyörgy Zoltán, 532
 * L6-3 Adott egy 𝑛 egész szám. Határozzuk meg a legkisebb olyan 𝑚 > 0 természetes
számot, amelyre 𝑚 számjegyeinek szorzata egyenlő 𝑛-el!
 */

#include <iostream>
#include <climits>

using namespace std;

void lkSzam(int n)
{
	unsigned long long p = 1, m = 0;
	int i = 9;
	if (n == 0)
	{
		cout << 10 << endl;
	}
	else if (n == 1)
	{
		cout << 1 << endl;
	}
	else
	{
		for (; i >= 2; i--)
		{
			while (n != 0 && n % i == 0)
			{
				m += p * i;
				p *= 10;
				n /= i;
			}
			if (m >= LONG_MAX) // m szamjegyeinek szorzata nagyobb lesz mint n biztosan
			{
				i = 0;
				break;
			}
		}
		if (n != 1 || i == 0)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << m << endl;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	lkSzam(n);
	return 0;
}
