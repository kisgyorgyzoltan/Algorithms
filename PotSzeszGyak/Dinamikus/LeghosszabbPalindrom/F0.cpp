/*
 * Kisgyörgy Zoltán, 532
 * L8-
 */

#include <iostream>
#include <string>

using namespace std;

void seged(int bal, int jobb, string s, string &er, int &hossz)
{
	while (bal >= 0 && jobb < s.size() && s[bal] == s[jobb])
	{
		if (jobb - bal + 1 > hossz)
		{
			er = s.substr(bal, jobb + 1);
			hossz = jobb - bal + 1;
		}
		bal--;
		jobb++;
	}
}

void palindrom(string s)
{
	string er = "";
	int hossz = 0;
	for (int i = 0; i < s.size(); i++)
	{
		seged(i, i, s, er, hossz); // paratlan hosszusagu
		seged(i, i + 1, s, er, hossz); // paros hosszusagu
	}
	cout << er << endl;
	cout << hossz;
}

int main()
{
	string s;
	cin >> s;
	palindrom(s);
	return 0;
}
