/*
* Kisgy�rgy Zolt�n, 532
* L2 - 3. Sz�moljuk meg egy adott sz�vegben a mag�nhangz�k sz�m�t!
*/

#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
    string be; 
    int db = 0;
    ifstream f("2149_2_3_3.in");
    getline(f, be); // hossz, stl string hasznalata eseten nincs szukseg tarolasara
    getline(f, be);
    f.close();
    ofstream g("2149_2_3_3.out");
    for (int i = 0; i < be.length(); i++)
    {
        if (strchr("aeiouAEIOU", be.at(i)) != NULL)
        {
            db++;
        }
    }
    g << db;
    g.close();
    return 0;
}