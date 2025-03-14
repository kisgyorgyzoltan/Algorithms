/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>

using namespace std;

int hoare(int bal, int jobb, vector<int>& v)
{
	int strazsa = v[bal], i = bal - 1, j = jobb + 1;
	do
	{
		do
		{
			j--;
		} while (v[j] > strazsa);
		do
		{
			i++;
		} while (v[i] < strazsa);
		if (i < j)
		{
			swap(v[i], v[j]);
		}
	} while (i < j);
	return j;
}

void qs(int b, int j, vector<int>& v)
{
	if (b < j)
	{
		int m = hoare(b, j, v);
		qs(b, m, v);
		qs(m + 1, j, v);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	qs(0, n - 1, v);
	for (int i = 0; i < n; i++)
	{
		cout <<  v[i] << " ";
	}
	return 0;
}
