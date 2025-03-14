/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>

using namespace std;

void beolvas(int& n, vector<int>& t)
{
	cin >> n;
	t.resize(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i];
	}
}

void reszhalmazok(int k, int n, vector<int>& t, vector<int>& rh, vector<vector<int>>& er)
{
	er.push_back(rh);
	for (int i = k; i < t.size(); i++)
	{
		rh.push_back(t[i]);
		reszhalmazok(i + 1, n, t, rh, er);
		rh.pop_back();
	}
}

int main()
{
	int n;
	vector<int> t, rh;
	beolvas(n, t);
	vector<vector<int>> eredmeny;
	reszhalmazok(1, n, t, rh, eredmeny);
	for (vector<int>& v : eredmeny)
	{
		for (int i: v)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}
