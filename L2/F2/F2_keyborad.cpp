/*
* Kisgyörgy Zoltán, 532
* L2 - 2. Határozzuk meg egy adott 𝑥 természetes szám legkisebb osztóját, amely
    nagyobb mint 1!
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	long long be;
	unsigned szam, oszto;
	cin >> be;
	if (be >= 0)
	{
		szam = be;
		if (szam >= 2)
		{
			if (szam % 2 == 0)
			{
				cout << 2 << endl;
			}
			else
			{
				double gyok = sqrt(szam);
				oszto = 3;
				while (szam % oszto != 0 && oszto <= gyok)
				{
					oszto += 2;
				}
				if (szam % oszto == 0)
				{
					cout << oszto << endl;
				}
				else
				{
					cout << szam << endl;
				}
			}
		}
	}
	return 0;
}
