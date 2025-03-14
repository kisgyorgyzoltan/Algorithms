/*
* Kisgyörgy Zoltán, 532
* L2 - 2. Határozzuk meg egy adott 𝑥 természetes szám legkisebb osztóját, amely
	nagyobb mint 1!
*/

#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int main()
{
	long long be;
	unsigned szam, oszto;
	ifstream f("2149_2_2_3.in");
	f >> be;
	f.close();
	ofstream g("2149_2_2_3.out");
	if (be >= 0)
	{
		szam = be;
		if (szam >= 2)
		{
			if (szam % 2 == 0)
			{
				g << 2 << endl;
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
					g << oszto << endl;
				}
				else
				{
					g << szam << endl;
				}
			}
		}
	}
	g.close();
	return 0;
}
