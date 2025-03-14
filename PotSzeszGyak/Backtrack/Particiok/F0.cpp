/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>

using namespace std;

void particiok(int k, int s, vector<int>& v, int n)
{
	for (int i = 1; i <= s; i++)
	{
		v[k] = i;
		if (i < s)
		{
			particiok(k + 1, s - i, v, n );
		}
		else
		{
			cout << n << " = ";
			for (int j = 1; j < k; j++)
			{
				cout << v[j] << " + ";
			}
			cout << v[k] << endl;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n + 1, 0);
	particiok(1, n, v, n);
	return 0;
}
