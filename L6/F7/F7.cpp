/*
 * Kisgyörgy Zoltán, 532
 * L6-7 Egy online áruház 𝑛 terméket kínál eladásra és mindegyikre ismert a profit
mely az eladásából származik és a határidő, ameddig el lehet adni. Mivel az
áruháznak nagyon kevés alkalmazottja van, egy napon csak egy terméket tud
eladni. Határozzuk meg a maximális profitot amire az áruház szert tehet!
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void beolvas(int& n, vector<pair<int,int>>& termekek)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int profit, hatarido;
		cin >> profit >> hatarido;
		termekek.push_back(make_pair(profit, hatarido));
	}
}

unsigned long long profit(vector<pair<int, int>>& termekek)
{
    int n = termekek.size();
    unsigned long long osszProfit = 0;
    vector<bool> napok(n, false);
    
	// profit szerint csökkenő sorrendbe rendezzük a termékeket
	sort(termekek.begin(), termekek.end(), [](pair<int, int> &a, pair<int, int> &b) { return a.first > b.first; });

    for (int i = 0; i < n; i++)
    {
        int j = min(n, termekek[i].second) - 1; // a határidő napjának indexe
        while (j >= 0)
        {
            if (!napok[j]) // ha nem volt meg eladva semmi aznap
            {
				napok[j] = true;
				osszProfit += termekek[i].first;
				break;
			}
			j--;
		}
    }
	return osszProfit;
}

int main()
{
	int n;
	vector<pair<int, int>> termekek;
	beolvas(n, termekek);
	cout << profit(termekek) << endl;

	return 0;
}
