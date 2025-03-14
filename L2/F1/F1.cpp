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

using namespace std;

bool haromSzigoruanNagyobb(vector<pair<string, double>>& diakok, string& keresett)
{
    int db = 0, n = diakok.size();
    pair<string, double> keresettDiak;
    keresettDiak.first = "";
    keresettDiak.second = -1;
    for (int i = 0; i < n; i++)
    {
        if (diakok.at(i).first == keresett)
        {
            keresettDiak = diakok.at(i);
            break;
        }
    }
    if (keresettDiak.first == "" || keresettDiak.second == -1)
    {
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        if (diakok.at(i).second > keresettDiak.second)
        {
            db++;
        }
    }
    return db >= 3;
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

    if (haromSzigoruanNagyobb(diakok, keresett))
    {
        cout << "nem";
    }
    else
    {
        cout << "igen";
    }
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