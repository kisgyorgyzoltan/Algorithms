/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>

using namespace std;

int hoare(vector<int>& v, int bal, int jobb)
{
	int strazsa = v[bal], i = bal - 1, j = jobb + 1;
	do
	{
		do
		{
			i++;
		} while (v[i] < strazsa);
		do
		{
			j--;
		} while (v[j] > strazsa);
		if (i <	j)
		{
			swap(v[i], v[j]);
		}
	} while (i < j);
	return j;
}

void qs(vector<int>& v, int b, int j)
{
	if (b < j)
	{
		int m = hoare(v, b, j);
		qs(v, b, m);
		qs(v, m + 1, j);
	}
}

int lomuto(vector<int>& v, int bal, int jobb)
{
	int strazsa = v[jobb], i = bal - 1;
	for (int j = bal; j <= jobb - 1; j++)
	{
		if (v[j] <= strazsa)
		{
			i++;
			swap(v[i], v[j]);
		}
	}
	swap(v[i + 1], v[jobb]);
	return i + 1;
}

void qs2(vector<int>& v, int b, int j)
{
	if (b < j)
	{
		int m = lomuto(v, b, j);
		qs(v, b, m - 1);
		qs(v, m + 1, j);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	//qs(v, 1, n);
	qs2(v, 1, n);
	for (int i = 1; i <= n; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}
