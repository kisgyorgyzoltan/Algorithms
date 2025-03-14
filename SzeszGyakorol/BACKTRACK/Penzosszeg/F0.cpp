/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>

using namespace std;

void fizet(int k, int n, vector<int>& db, vector<int>& b, int s)
{
	if (k == n)
	{
		if (s % b[n] == 0)
		{
			db[n] = s / b[n];
			for (int i = 1; i <= n; i++)
			{
				cout << b[i] << " : " << db[i] << endl;
			}
			cout << endl;
		}
	}
	else
	{
		for (db[k] = 0; db[k] <= s / b[k]; db[k]++)
		{
			int maradek = s - db[k] * b[k];
			if (maradek == 0)
			{
				for (int i = 1; i <= k; i++)
				{
					cout << b[i] << " : " << db[i] << endl;
				}
				cout << endl;
			}
			else
			{
				fizet(k + 1, n, db, b, maradek);
			}
		}
	}
}

int main()
{
	int n, s;
	cin >> n >> s;
	vector<int> b(n + 1, 0), db(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	fizet(1, n, db, b, s);
	return 0;
}
