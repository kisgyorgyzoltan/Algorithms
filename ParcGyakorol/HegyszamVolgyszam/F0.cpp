/*
 * Kisgyörgy Zoltán, 532
 * L4- 
 */

#include <iostream>

using namespace std;

void hegyszamVolgyszam(int& n, int*& a)
{
	int i = 0;
	while (i < n - 1 && a[i] == a[i + 1]) // first > or < number
	{
		i++;
	}

	if (i < n - 1)
	{
		bool increasing = (a[i] < a[i + 1]);
		if (!increasing)
		{
			while (i < n - 1 && a[i] >= a[i + 1])
			{
				i++;
			}
			if (i < n - 1)
			{
				while (i < n - 1 && a[i] <= a[i + 1])
				{
					i++;
				}
				if (i >= n - 1)
				{
					cout << "volgy";
				}
				else
				{
					cout << "egyik se";
				}
			}
			else
			{
				cout << "egyik se";
			}
		}
		else
		{
			while (i < n - 1 && a[i] <= a[i + 1])
			{
				i++;
			}
			if (i < n - 1)
			{
				while (i < n - 1 && a[i] >= a[i + 1])
				{
					i++;
				}
				if (i >= n - 1)
				{
					cout << "hegy";
				}
				else
				{
					cout << "egyik se";
				}
			}
			else
			{
				cout << "egyik se";
			}
		}
		
	}
	else
	{
		cout << "egyik se, mind egyenloek";
	}
	
}

void beolvas(int& n, int*& a)
{
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

int main()
{
	int* a, n;
	beolvas(n, a);
	hegyszamVolgyszam(n, a);
	delete[] a;
	return 0;
}
