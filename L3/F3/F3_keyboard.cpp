/*
* Kisgyörgy Zoltán, 532
* L3 - 3. Adott egy római szám, írjuk ki arab számjegyekkel!
*/

#include <iostream>
#include <string>

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

int romaibol(string& s)
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
    cin >> s;
    cout << "A megadott szam arab szamjegyekkel: " << romaibol(s);
    
    return 0;
}