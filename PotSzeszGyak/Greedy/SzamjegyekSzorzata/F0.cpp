/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <climits>

using namespace std;

void szj(int n)
{
	unsigned long long p = 1, m = 0;
	int i = 9;
	if (n == 0)
	{
		cout << 10;
	}
	else if (n == 1)
	{
		cout << 1;
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
			if (m >= LONG_MAX)
			{
				i = 0;
				break;
			}
		}
		if (n != 1 || i == 0)
		{
			cout << -1;
		}
		else
		{
			cout << m;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	szj(n);
	return 0;
}
