/*
* Kisgyörgy Zoltán, 532
* L3 - 1. Bontsunk fel egy adott számot 2 hatványainak összegére!
*/

#include <iostream>
#include <vector>

#include <fstream>

using namespace std;

bool leszKovetkezo(int i, vector<long int>& hatv)
{
	while (i >= 0)
	{
		if (hatv[i] > 0)
			return true;
		i--;
	}
	return false;
}

void felbont(unsigned long  n)
{
    vector<long int> hatv;
    int hossz;
	ofstream g("2149_3_1_3.out");
    while (n > 0)
    {
        hatv.push_back(n % 2);
        n = n / 2;
    }
	hossz = hatv.size();
	
	for (int i = hossz - 1; i >= 0; i--)
	{
		if (hatv[i] == 1)
		{
			cout << "2^" << i;
			g << "2^" << i;
			if (leszKovetkezo(i - 1, hatv))
			{
				cout << "+";
				g << "+";
			}
			else
			{
				break;
			}
		}
	}
	g.close();
}

int main()
{
	unsigned long n;
	//cin >> n;
	ifstream f("2149_3_1_3.in");
	f >> n;
	f.close();
	felbont(n);

    return 0;
}
