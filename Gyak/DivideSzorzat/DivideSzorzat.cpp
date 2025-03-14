#include <iostream>
#include <vector>

using namespace std;

long long szorzat(vector<int> v, int bal, int jobb)
{
	if (bal == jobb)
	{
		return v[bal];
	}
	else
	{
		int kozep = (bal + jobb) / 2;
		long long balsz = szorzat(v, bal, kozep);
		long long jobbsz = szorzat(v, kozep + 1, jobb);
		return balsz * jobbsz;
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
	cout << szorzat(v, 1, n);
	return 0;
}
