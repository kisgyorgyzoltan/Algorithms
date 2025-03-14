/*
 * Kisgyörgy Zoltán, 532
 * L4- 
 */

#include <iostream>
#include <cmath>

using namespace std;

void szita(int n, bool*&a)
{
	a[0] = false;
	a[1] = false;
	for (int i = 2; i <= n; i++)
	{
		a[i] = true;
	}
	double gyok = sqrt(n);
	for (int i = 2; i <= gyok; i++)
	{
		if (a[i])
		{
			int j = i * i;
			while (j <= n)
			{
				a[j] = false;
				j += i;
			}
		}
	}
}

// Driver code
int main()
{
	int n;
	cin >> n;
	bool* a = new bool[n + 1];
	szita(n, a);
	for (int i = 0; i <=n; i++)
	{
		if (a[i])
		{
			cout << i << " ";
		}
	}
	return 0;
}
