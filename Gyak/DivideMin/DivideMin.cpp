#include <iostream>
#include <vector>

using namespace std;

int minv(vector<int> v, int bal, int jobb)
{
	if (bal == jobb)
	{
		return min(v[bal],v[jobb]);
	}
	else
	{
		int kozep = (bal + jobb) / 2;
		long long balmin = minv(v, bal, kozep);
		long long jobbmin = minv(v, kozep + 1, jobb);
		return min(balmin, jobbmin);
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
	cout << minv(v, 1, n);
	return 0;
}
