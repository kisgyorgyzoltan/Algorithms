/*
 * Kisgyörgy Zoltán, 532
 * L4-9 Implementáljuk rekurzívan az orosz szorzás algoritmusát!
 */

#include <iostream>

using namespace std;

unsigned long long oroszSzorzas(unsigned long long a, unsigned long long b)
{
	if (b <= 0)
	{
		return 0;
	}
	else
	{
		if (b % 2 == 1)
		{
			return a + oroszSzorzas(a * 2, b / 2);
		}
		return oroszSzorzas(a * 2, b / 2);
	}
}


int main()
{
	unsigned long long a, b;
	cin >> a >> b;
	cout << oroszSzorzas(a, b);
	return 0;
}
