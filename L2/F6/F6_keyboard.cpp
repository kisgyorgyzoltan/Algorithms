/*
* Kisgyörgy Zoltán, 532
* L2 - 6. Ismerjük két szám prímszámosztóit, határozzuk meg a két szám legkisebb
    közös többszörösének prímszámosztóit! (A két számot nem ismerjük, csupán a
    prímosztóikat).
*/


#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void beolvas(vector<unsigned long long int>& osztok1, vector<unsigned long long int>& osztok2)
{
	string sor, szam;
    int i = 0;
    unsigned long long int seged;
	std::getline(cin, sor);
    seged = stoi(sor);
	osztok1.resize(seged);

    std::getline(cin, sor);
	istringstream iss(sor);
    while (iss >> szam)
    {
        seged = stoull(szam);
        osztok1[i] = seged;
        i++;
    }

    std::getline(cin, sor);
    seged = stoi(sor);
    osztok2.resize(seged);

    std::getline(cin, sor);
	iss.clear();
	iss.str(sor);

    i = 0;
    while (iss >> szam)
    {
        osztok2[i] = stoi(szam);
        i++;
    }
}

void kiir(vector<unsigned long long int>& osztok)
{
    int n = osztok.size();
	for (int i = 0; i < n; i++)
	{
		cout << osztok[i] << " ";
	}
	cout << endl;
}

vector<unsigned long long int> egyesites(vector<unsigned long long int>& osztok1, vector<unsigned long long int>& osztok2)
{
	vector<unsigned long long int> egyesitett = osztok1;
    int i, j, n = osztok1.size(), m = osztok2.size();
    for (j = 0; j < m; j++)
    {
        i = 0;
        while ((i < n) && (osztok1[i] != osztok2[j]))
        {
            i++;
        }
        if (i >= n)
        {
            egyesitett.push_back(osztok2[j]);
        }
    }
	return egyesitett;
}
int main()
{
	vector<unsigned long long int> osztok1, osztok2, eredmeny;
	beolvas(osztok1, osztok2);
	eredmeny = egyesites(osztok1, osztok2);
	kiir(eredmeny);
    
    return 0;
}
