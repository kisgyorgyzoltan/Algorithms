/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <vector>

using namespace std;

bool jo(long n, long x, vector<long>& szamok, vector<int>& v)
{
	long er = szamok[1];
	for (int i = 1; i <= n - 1; i++)
	{
		switch (v[i])
		{
		case 1: // +
			er += szamok[i + 1];
			break;
		case 2: // -
			er -= szamok[i + 1];
			break;
		case 3: // *
			er *= szamok[i + 1];
			break;
		case 4: // /
			if (er % szamok[i + 1] != 0 || szamok[i + 1] == 0)
				return false;
			er /= szamok[i + 1];
			break;
		default:
			return false;
			break;
		}
	}
	return er == x;
}

char kar(int m)
{
	switch (m)
	{
	case 1: // +
		return '+';
		break;
	case 2: // -
		return '-';
		break;
	case 3: // *
		return '*';
		break;
	case 4: // /
		return '/';
		break;
	default:
		return '$';
		break;
	}
}

void kiir(long n, long x, vector<long>& szamok, vector<int>& v)
{
	cout << x << "=" << szamok[1];
	for (int i = 1; i <= n - 1; i++)
	{
		cout << kar(v[i]) << szamok[i + 1] ;
	}
	cout << endl;
}

void muvelet(int k, long n, long x, vector<long>& szamok, vector<int>& v)
{
	if (k <= n - 1)
	{
		for (int i = 1; i <= 4; i++)
		{
			v[k] = i;
			muvelet(k + 1, n, x, szamok, v);
		}
	}
	else
	{
		if (jo(n, x, szamok, v))
		{
			kiir(n, x, szamok, v);
		}
	}
}

int main()
{
	long n, x;
	vector<long> szamok;
	vector<int> v;

	cin >> n;
	szamok.resize(n + 1, -1);
	v.resize(n, -1);
	for (int i = 1; i <= n; i++)
	{
		cin >> szamok[i];
	}
	cin >> x;

	muvelet(1, n, x, szamok, v);
	return 0;
}
