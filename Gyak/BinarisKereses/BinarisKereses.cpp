#include <iostream>
#include <vector>

using namespace std;

int binkeres(vector<int> v, int bal, int jobb, int keresett)
{
	if (bal > jobb)
	{
		return -1;
	}
	else
	{
		int kozep = (bal + jobb) / 2;
		if (keresett < v[kozep])
		{
			return binkeres(v, bal, kozep - 1,keresett);
		}
		else
		{
			if (keresett > v[kozep])
			{
				return binkeres(v, kozep + 1, jobb, keresett);
			}
			else
			{
				return kozep;
			}
		}
	}
}

int main()
{
	int n, x;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	cin >> x;
	cout << endl;
	cout << binkeres(v, 1, n, x);
	return 0;
}
