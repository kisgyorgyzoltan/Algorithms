/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;


string lcs(vector<vector<int>>& dp, int n, int m, int i, int j, string s1, string s2)
{
	if (i == n || j == m) return "";
	if (s1[i] == s2[j])
	{
		return s1[i] + lcs(dp, n, m, i + 1, j + 1, s1, s2);
	}
	if (dp[i][j+1] > dp[i+1][j])
	{
		return lcs(dp, n, m, i, j + 1, s1, s2);
	}
	return lcs(dp, n, m, i + 1, j, s1, s2);
}

int lh(string s1, string s2, vector<vector<int>>& dp)
{
	for (int i = s1.size() - 1; i > -1; i--)
	{
		for (int j = s2.size() - 1; j > -1; j--)
		{
			if (s1[i] == s2[j])
			{
				dp[i][j] = 1 + dp[i + 1][j + 1];
			}
			else
			{
				dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}

	cout << lcs(dp, s1.size(), s2.size(), 0, 0, s1, s2) << endl;

	return dp[0][0];
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
	cout << lh(s1,s2, dp);
	return 0;
}
