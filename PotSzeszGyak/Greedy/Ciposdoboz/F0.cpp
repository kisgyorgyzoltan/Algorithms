/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int elsoRossz(int n, vector<int>& melyikben)
{
	for (int i = 1; i <= n; i++)
	{
		if (melyikben[i] != i) return i;
	}
	return -1;
}

void cipok(int n, vector<int>& dobozok, vector<int>& melyikben, vector<pair<int,int>>& lepesek)
{
	while (true)
	{
		if (melyikben[0] != n + 1)
		{
			int k = melyikben[0];
			lepesek.push_back(make_pair(melyikben[k], melyikben[0]));
			swap(dobozok[melyikben[k]], dobozok[melyikben[0]]);
			swap(melyikben[k], melyikben[0]);
		}
		else
		{
			int k = elsoRossz(n, melyikben);
			if (k == -1) return;
			int elem = dobozok[k];
			lepesek.push_back(make_pair(k, melyikben[0]));
			swap(dobozok[k], dobozok[melyikben[0]]);
			swap(melyikben[elem], melyikben[0]);
		}

	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> dobozok(n + 2, 0), melyikben(n + 2, 0);
	vector<pair<int, int>> lepesek;
	for (int i = 1; i <= n + 1; i++)
	{
		cin >> dobozok[i];
		melyikben[dobozok[i]] = i;
	}
	cipok(n,dobozok, melyikben, lepesek);
	cout << lepesek.size() << endl;
	for (auto p:lepesek)
	{
		cout << p.first << " " << p.second << endl;
	}
	return 0;
}
