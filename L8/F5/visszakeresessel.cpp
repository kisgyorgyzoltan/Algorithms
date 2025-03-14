/*
 * Kisgyörgy Zoltán, 532
 * L8-5 Határozzuk meg az 𝑛 elemű 𝑎 sorozat és az 𝑚 elemű 𝑏 sorozat egy leghosszabb
közös tömbszakaszát!
 */

#include <iostream>
#include <vector>

using namespace std;

void beolvas(int& n, int &m, vector<long>& a, vector<long>& b)
{
	cin >> n;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> m;
	b.resize(m + 1);
	for (int i = 1; i <= m; i++)
		cin >> b[i];
}

void visszakeres(vector<vector<int>>& dp, vector<long>& a, vector<long>& b, int n, int m)
{
	if (n == 0 || m == 0)
		return;
	if (a[n] == b[m])
	{
		visszakeres(dp, a, b, n - 1, m - 1); // átlósan haladunk vissza
		cout << "[" << n << ", " << m << "] " << a[n] << endl; // kiírjuk az elemeket, amik egyeznek
	}
	else if (dp[n - 1][m] > dp[n][m - 1])
	{
		visszakeres(dp, a, b, n - 1, m); // balra haladunk vissza
	}
	else
	{
		visszakeres(dp, a, b, n, m - 1); // felfelé haladunk vissza
	}
}

void leghosszabbKozosTombSzakasz(int n, int m, vector<long>& a, vector<long>& b)
{
	int aIndex = 0, bIndex = 0, maximum = 0;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i] == b[j]) // ha egyezik a két elem, akkor a bal felső sarokból jön az újabb elem
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j] > maximum)
				{
					maximum = dp[i][j];
					aIndex = i;
					bIndex = j;
				}
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // ha nem egyezik, akkor a bal vagy a felső elemből jön az újabb elem
			}
		}
	}
	cout << dp[n][m] << endl;
	cout << aIndex - maximum + 1 << " " << bIndex - maximum + 1 << endl;	
	//visszakeres(dp, a, b, aIndex, bIndex);
}

int main()
{
	int n, m;
	vector<long> a, b;
	beolvas(n, m, a, b);
	leghosszabbKozosTombSzakasz(n, m, a, b);
	return 0;
}
