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
#include <algorithm>

using namespace std;

int szures(int i, vector<pair<string, double>>& diakok, vector<string>& eredmeny)
{
    double atlag = diakok.at(i).second;
    int diakokszama = diakok.size();
    while (i < diakokszama && diakok.at(i).second == atlag)
    {
        eredmeny.push_back(diakok.at(i).first);
        i++;
    }
    if (i < diakokszama)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

bool tartalmazza(vector<string>& tomb, string& str)
{
    int tombmeret = tomb.size();
    for (int i = 0; i < tombmeret; i++)
    {
        if (tomb.at(i) == str)
        {
            return true;
        }
    }
    return false;
}

void beolvas(int& n, vector<pair<string, double>>& diakok, string& keresett)
{
    string csnev, knev, teljesnev, stringbuffer;
    double atlag;

    getline(cin, stringbuffer, '\n');
    n = stoi(stringbuffer);


    for (int i = 0; i < n; i++)
    {
        getline(cin, stringbuffer, '\n');
        getline(cin, teljesnev, '\n');

        getline(cin, stringbuffer, '\n');
        atlag = stod(stringbuffer);

        diakok.push_back(make_pair(teljesnev, atlag));
    }
    getline(cin, stringbuffer, '\n');
    getline(cin, keresett, '\n');
}

void elsoharom(int n, vector<pair<string, double>>& diakok, string& keresett)
{
    bool bennevan = false;
    for (pair<string, double> diak : diakok)
    {
        if (diak.first == keresett)
        {
            bennevan = true;
        }
    }

    if (!bennevan)
    {
        cout << "nem";
        return;
    }

    if (n <= 3)
    {
        cout << "igen";
        return;
    }

    vector<string> elsok, masodikok, harmadikok;
    int seged;

    // diakok rendezese csokkeno sorrendbe
    sort(diakok.begin(), diakok.end(), [](const pair<string, double>& lhs, const pair<string, double>& rhs)
        { return lhs.second > rhs.second; });

    // elso helyek
    seged = szures(0, diakok, elsok);
    if (tartalmazza(elsok, keresett))
    {
        cout << "igen";
        return;
    }

    // masodik helyek
    int elsokszama;
    if (seged != -1)
    {
        seged = szures(seged, diakok, masodikok);
        elsokszama = elsok.size();
        if (tartalmazza(masodikok, keresett) && elsokszama < 3)
        {
            cout << "igen";
            return;
        }
    }

    // harmadikok
    if (seged != -1)
    {
        seged = szures(seged, diakok, harmadikok);
        int masodikokszama = masodikok.size();
        int tobbiszama = elsokszama + masodikokszama;
        if (tartalmazza(harmadikok, keresett) && tobbiszama < 3)
        {
            cout << "igen";
            return;
        }
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
