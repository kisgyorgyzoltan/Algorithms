/*
 * Kisgy�rgy Zolt�n, 532
 * L3 - 3. Adott egy r�mai sz�m, �rjuk ki arab sz�mjegyekkel!
 */

#include <iostream>
#include <string>

#include <fstream>

using namespace std;

int ertek(char c)
{
    switch (c)
    {
    case 'I':
        return 1;
        break;

    case 'V':
        return 5;
        break;

    case 'X':
        return 10;
        break;

    case 'L':
        return 50;
        break;

    case 'C':
        return 100;
        break;

    case 'D':
        return 500;
        break;

    case 'M':
        return 1000;
        break;

    default:
        return -1;
        break;
    }
}

int romaibol(string &s)
{
    int szam = 0, hossz = s.length();
    for (int i = 0; i < hossz; i++)
    {
        int szj1 = ertek(s.at(i));
        if (i + 1 < hossz)
        {
            int szj2 = ertek(s.at(i + 1));
            if (szj1 >= szj2)
            {
                szam += szj1;
            }
            else
            {
                szam += szj2 - szj1;
                i++;
            }
        }
        else
        {
            szam += szj1;
        }
    }
    return szam;
}

int main()
{
    string s;
    // cin >> s;
    ifstream f("2149_3_3_3.in");
    f >> s;
    f.close();
    ofstream g("2149_3_3_3.out");
    cout << "A megadott szam arab szamjegyekkel: " << romaibol(s);
    g << "A megadott szam arab szamjegyekkel: " << romaibol(s);
    g.close();

    return 0;
}