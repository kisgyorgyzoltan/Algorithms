/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

unsigned long long c(int n, int k, map<pair<int, int>, unsigned long long> &memo)
{
	pair<int, int> p = make_pair(n, k);
	if (memo.count(p) == 1) return memo[p];
	if (k > n)
	{
		memo[p] = 0;
		return 0;
	}
	if (k == 0 || k == n)
	{
		memo[p] = 1;
		return 1;
	}
	memo[p] = c(n - 1, k - 1, memo) + c(n - 1, k, memo);
	return memo[p];
}

int main()
{
	int n, k; 
	cin >> n >> k;
	map<pair<int, int>, unsigned long long> memo;
	cout << c(n, k, memo);
	return 0;
}
