/*
* Kisgyörgy Zoltán, 532
* L1 - 8.
* Számítsuk ki hány szökőév volt/lesz két különböző évszám között, mindkét
	évszámot beleszámítva! A két évszám előjel nélküli 64-bites egész.
*/

#include <iostream>

using namespace std;

void swap(unsigned& a, unsigned& b) {
	unsigned temp = a;
	a = b;
	b = temp;
}

unsigned nullaszoko(unsigned ev)
{
	return(ev / 4 - ev / 100 + ev / 400);
}

unsigned szokoEv(unsigned ev)
{
	if (ev % 4 == 0 && ev % 100 != 0 || ev % 400 == 0)
		return 1;
	return 0;
}

unsigned szokoevek(unsigned ev1, unsigned ev2)
{
	return(nullaszoko(ev2) - nullaszoko(ev1) + szokoEv(ev1));
}

int main()
{
	unsigned a = 0, b = 0, k;
	cin >> a >> b;

	if (a != b)
	{
		if (max(a, b) == a)
		{
			swap(a, b);
		}
		k = szokoevek(a, b);
		cout << k << endl;
	}
	else
	{
		cout << szokoEv(a) << endl;
	}

	return 0;
}
