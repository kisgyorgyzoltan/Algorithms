/*
 * Kisgyörgy Zoltán, 532
 * 1 szo n szodarab
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

bool lehet(string szo, vector<string>& szodarabok, map<string, bool>& memo)
{
	if (szo == "") return true;
	if (memo.count(szo) == 1) return memo[szo];
	for (auto darab:szodarabok)
	{
		if (szo.compare(0, darab.size(), darab) == 0)
		{
			if (lehet(szo.substr(darab.size(), szo.size()), szodarabok, memo))
			{ 
				memo[szo] = true;
				return true; 
			}
		}
	}

	memo[szo] = false;
	return false;
}

int main()
{
	map<string, bool> memo;
	vector<string> szodarabok;
	string szo;
	cin >> szo;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		szodarabok.push_back(s);
	}
	if (lehet(szo, szodarabok, memo))
	{
		cout << "igen";
	}
	else
	{
		cout << "nem";
	}
	return 0;
}
