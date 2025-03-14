/*
 * Kisgyörgy Zoltán, 532
 * L7-7 Adott 𝑛 elemű 𝑎 sorozat, melyre igaz, hogy 𝑎1 > 𝑎2 és 𝑎𝑛−1 < 𝑎𝑛. Lokális
minimumnak nevezünk minden olyan 𝑎𝑖 elemet, amelyre 𝑎𝑖−1 > 𝑎𝑖 < 𝑎𝑖+1 és
𝑖 = 2, 𝑛 − 1. Határozzunk meg egy tetszőleges lokális minimumot egy tömbben,
melynek kezdetben ismeretlenek az elemei!

 */

#include <iostream>
#include <vector>

using namespace std;

void keres(int bal, int jobb, vector<int> &v, bool &talalt)
{
	if (bal < jobb)
	{
		int kozep = (bal + jobb) / 2;
		bool balJo = false, jobbJo = false, megVan = false;
		if (kozep > 1 && kozep < v.size() - 1)
		{
			if (v[kozep] == 0)
			{
				cout << 0 << " " << kozep << endl;
				cin >> v[kozep];
			}
			if (v[kozep + 1] == 0 && kozep + 1 != v.size() - 1)
			{
				cout << 0 << " " << kozep + 1 << endl;
				cin >> v[kozep + 1];
			}
			jobbJo = v[kozep] < v[kozep + 1] || kozep + 1 == v.size() - 1;
			if (jobbJo)
			{
				if (v[kozep - 1] == 0 && kozep - 1 != 1)
				{
					cout << 0 << " " << kozep - 1 << endl;
					cin >> v[kozep - 1];
				}
				balJo = v[kozep] < v[kozep - 1] || kozep - 1 == 1;
			}
			megVan = balJo && jobbJo;
			if (megVan)
			{
				cout << 1 << " " << kozep << endl;
				talalt = true;
				return;
			}
			else
			{
				keres(bal, kozep - 1, v, talalt);
				if (!talalt)
					keres(kozep + 1, jobb, v, talalt);
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n + 1, 0);
	bool talalt = false;
	keres(1, n, v, talalt);
	return 0;
}
