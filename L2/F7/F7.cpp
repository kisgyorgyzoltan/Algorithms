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

using namespace std;

void beolvas(int& n, vector<string>& nevek)
{
    int dbcsoport, dbnev, i, j;
    string hossz, nev;
    getline(cin, hossz, '\n');
    dbcsoport = stoi(hossz);
    i = 0;
    while (i < dbcsoport)
    {
        getline(cin, hossz, '\n');
        dbnev = stoi(hossz);
        j = 0;
        while (j < dbnev)
        {
            getline(cin, hossz, '\n');
            getline(cin, nev, '\n');
            nevek.push_back(nev);
            j++;
        }
        i++;
    }
    n = nevek.size();
}
void kiir(int n, vector<string>& nevek)
{
    for (int i = 0; i < n; i++)
    {
        cout << nevek[i] << endl;
    }
    cout << endl;
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
