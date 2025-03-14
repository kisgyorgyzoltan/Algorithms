/*
* Kisgyörgy Zoltán, 532
* L2 - 1.
* Ismerjük egy osztály tanulóinak neveit (családnév + keresztnév) és év végi
    átlagait. Állapítsuk meg, hogy egy adott nevű tanuló az első három díjazott
    között van-e?
*/

#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <vector>
#include <utility> 
#include<algorithm>

#include <fstream>

using namespace std;

int szures(int i, vector<pair<string, double>>& diakok, vector<string>& eredmeny)
{
    double atlag = diakok.at(i).second;
    while (i < diakok.size() && diakok.at(i).second == atlag)
    {
        eredmeny.push_back(diakok.at(i).first);
        i++;
    }

    return i;
}

bool tartalmazza(vector<string>& tomb, string &str)
{
	for (int i = 0; i < tomb.size(); i++)
	{
		if (tomb.at(i) == str)
		{
			return true;
		}
	}
	return false;
}

void beolvas(int& n, vector<pair<string, double>>& diakok, string &keresett)
{
    int len;
    string csnev, knev, diakszamok, teljesnev;
    double atlag;
    //cin >> n;

    ifstream f("2149_2_1_1.in");
    f >> n;

    for (int i = 0; i < n; i++)
    {
        //cin >> len;
        //cin >> csnev[i];
        //cin >> knev[i];
        //cin >> atlagok[i];
        f >> len;
        f >> csnev;
        f >> knev;        
		teljesnev = csnev + " " + knev;
        
        f >> atlag;

		diakok.push_back(make_pair(teljesnev, atlag));
    }
    //cin >> keres[0] >> keres[1];
	f >> len;
	f >> csnev;
	f >> knev;
	keresett = csnev + " " + knev;
    f.close();
}
void elsoharom(int n, vector<pair<string,double>> &diakok, string &keresett)
{
	if (n <= 3)
	{
		cout << "igen" << endl;
		return;
	}

    vector<string> elsok, masodikok, harmadikok;
    int seged;
	sort(diakok.begin(), diakok.end(), [](const pair<string, double>& lhs, const pair<string, double>& rhs) {
		return lhs.second > rhs.second; });
    
    // elso helyek
	seged = szures(0, diakok, elsok);
    if (tartalmazza(elsok, keresett))
    {
        cout << "igen";
		return;
    }
    
	// masodik helyek
	seged = szures(seged, diakok, masodikok);
    if (tartalmazza(masodikok, keresett))
    {
        cout << "igen";
        return;
    }
    
    // harmadikok
	seged = szures(seged, diakok, harmadikok);
    if (tartalmazza(harmadikok, keresett))
    {
        cout << "igen";
        return;
    }
    cout << "nem";
}
int main()
{
    int n;
    vector<pair<string, double>> diakok;
    string keresett;
    beolvas(n, diakok, keresett);
	elsoharom(n, diakok, keresett);

    return 0;
}
