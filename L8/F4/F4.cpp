/*
 * Kisgyörgy Zoltán, 532
 * L8-4 Adott egy 𝑛 soros és 𝑚 oszlopos bitmátrix. Határozzuk meg a legnagyobb
olyan négyzet oldalhosszát, amely a mátrixban található és csak 1-eseket tartalmaz!
 */

#include <iostream>
#include <vector>

using namespace std;

void beolvas(int& n, int& m, vector<vector<int>>& matrix)
{
	cin >> n >> m;
	matrix.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
				cin >> matrix[i][j];
		}
	}
}

int legnagyobb(int n, int m, vector<vector<int>>& matrix)
{
	int maxHossz = 0;
	vector<vector<int>> seged(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) // első oszlopot átmásolom
	{
		seged[i][0] = matrix[i][0];
	}
	for (int i = 0; i < m; i++) // első sort átmásolom
	{
		seged[0][i] = matrix[0][i];
	}

	// a többi elemet kiszámolom
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (matrix[i][j] == 1) // csak akkor számolok, ha 1-es
			{
				seged[i][j] = 1 + min(seged[i - 1][j], min(seged[i][j - 1], seged[i - 1][j - 1])); // L alakban számolok, fentről, balról, átlósan
			}
			else
			{
				seged[i][j] = 0; // ha 0, akkor 0
			}
		}
	}
	
	// a legnagyobb elemet keresem
	maxHossz = seged[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maxHossz < seged[i][j]) {
				maxHossz = seged[i][j];
			}
		}
	}

	return maxHossz;
}

int main()
{
	int n, m;
	vector<vector<int>> matrix;
	beolvas(n, m, matrix);
	cout << legnagyobb(n, m, matrix) << endl;

	return 0;
}
