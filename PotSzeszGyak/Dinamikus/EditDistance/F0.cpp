/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b, int c)
{
	return min(min(a, b), c);
}

int dist(string s1, string s2)
{
	int n = s1.size(), m = s2.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	// also sor
	for (int i = 0; i <= m; i++)
	{
		dp[n][i] = m - i;
	}
	// jobboldali oszlop
	for (int i = 0; i <= n; i++)
	{
		dp[i][m] = n - i;
	}


	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			if (s1[i] == s2[j])
			{
				dp[i][j] = dp[i + 1][j + 1];
			}
			else
			{
				dp[i][j] = 1 + min(dp[i][j + 1], dp[i + 1][j], dp[i + 1][j + 1]);
			}
		}
	}
	return dp[0][0];
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	cout << dist(s1, s2);
	return 0;
}
