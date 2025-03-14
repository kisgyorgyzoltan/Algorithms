/*
 * Kisgyörgy Zoltán, 532
 * L8-1 Számoljátok ki 𝑛 faktoriálisát a dinamikus programozás módszerével
 */

#include <iostream>
#include <vector>

using namespace std;

void faktorialis(int n)
{
	vector<unsigned long long> tomb(n + 1, 0);
	if (n >= 0)
	{
		tomb[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			tomb[i] = tomb[i - 1] * i;
		}
	}
	cout << tomb[n] << endl;
}

int main()
{
	int n;
	cin >> n;
	faktorialis(n);
	return 0;
}
