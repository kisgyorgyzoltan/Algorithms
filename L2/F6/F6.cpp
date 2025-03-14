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
#include <fstream>

using namespace std;

void beolvas(vector<unsigned long long int>& osztok1, vector<unsigned long long int>& osztok2)
{
	string sor, szam;
    int i = 0;
    unsigned long long int seged;
    ifstream f("2149_2_6_3.in");
	std::getline(f, sor);
    seged = stoi(sor);
	osztok1.resize(seged);

    std::getline(f, sor);
	istringstream iss(sor);
    while (iss >> szam)
    {
        seged = stoull(szam);
        osztok1[i] = seged;
        i++;
    }

    std::getline(f, sor);
    seged = stoi(sor);
    osztok2.resize(seged);

    std::getline(f, sor);
	iss.clear();
	iss.str(sor);

    i = 0;
    while (iss >> szam)
    {
        osztok2[i] = stoi(szam);
        i++;
    }
    f.close();
}

void kiir(vector<unsigned long long int>& osztok)
{
    ofstream g("2149_2_6_3.out");
    int n = osztok.size();
	for (int i = 0; i < n; i++)
	{
		g << osztok[i] << " ";
	}
	g << endl;
    g.close();
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
