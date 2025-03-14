/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>

using namespace std;

void particiok(vector<int>& v, int k, int s)
{
	for (int j = 1; j <= s; j++)
	{
		v[k] = j;
		if (j < s)
		{
			particiok(v, k + 1, s - j);
		}
		else
		{
			for (int i = 1; i <= k; i++)
			{
				cout << v[i] << " ";
			}
			cout << endl;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n+1);
	particiok(v, 1, n);
	return 0;
}
