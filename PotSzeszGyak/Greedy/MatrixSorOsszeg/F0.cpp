/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void osszeg(int n, int m, vector<vector<int>>& matrix)
{
	long osszeg = 0;
	int elozoMax = INT_MAX;
	for (int i = n; i >= 1; i--)
	{
		int sormax = INT_MIN;
		for (int j = 1; j <= m; j++)
		{
			if (matrix[i][j] > sormax && matrix[i][j] < elozoMax)
			{
				sormax = matrix[i][j];
			}
		}
		if (sormax == INT_MIN)
		{
			cout << "nincs megoldas";
			return;
		}
		osszeg += sormax;
		elozoMax = sormax;
	}
	cout << osszeg;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> matrix[i][j];
		}
	}

	osszeg(n, m, matrix);
	return 0;
}
