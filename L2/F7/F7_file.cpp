/*
* Kisgyörgy Zoltán, 532
* L2 - 7. Adottak az elsőéves egyetemisták névsorai (abc sorrendben), csoportonként.
Állítsunk elő ezekből egyetlen névsort, mely szintén abc sorrendben van!
*/

#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <vector>
#include <fstream>

using namespace std;

void beolvas(int& n, vector<string>& nevek)
{
    ifstream f("2149_2_7_3.in");
    int dbcsoport, dbnev;
    string hossz, nev;
    getline(f, hossz, '\n');
	dbcsoport = stoi(hossz);
    while (dbcsoport != 0)
    {
        getline(f, hossz, '\n');
        dbnev = stoi(hossz);
        while (dbnev != 0)
        {
			getline(f, hossz, '\n');
            getline(f, nev, '\n');
			nevek.push_back(nev);
            dbnev--;
        }
        dbcsoport--;
    }
	n = nevek.size();
    f.close();
}
void kiir(int n, vector<string>& nevek)
{
    ofstream g("2149_2_7_3.out");
    for (int i = 0; i < n; i++)
    {
        g << nevek[i] << endl;
    }
    g << endl;
    g.close();
}

void abc(int n, vector<string>& nevek)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
			if (nevek[j] < nevek[i])
			{
				string s;
				s = nevek[j];
				nevek[j] = nevek[i];
				nevek[i] = s;
			}
        }
    }
}
int main()
{
    int hossz;
    vector<string> nevek;
    beolvas(hossz, nevek);
    abc(hossz, nevek);
    kiir(hossz, nevek);
    return 0;
}
