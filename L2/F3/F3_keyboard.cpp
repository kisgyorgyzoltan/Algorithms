/*
* Kisgy�rgy Zolt�n, 532
* L2 - 3. Sz�moljuk meg egy adott sz�vegben a mag�nhangz�k sz�m�t!
*/

#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

int main()
{
    string be; 
    int db = 0;
    getline(cin, be); // hossz, stl string hasznalata eseten nincs szukseg tarolasara
    getline(cin, be);
    for (int i = 0; i < be.length(); i++)
    {
        if (strchr("aeiouAEIOU", be.at(i)) != NULL)
        {
            db++;
        }
    }
    cout << db;
    return 0;
}