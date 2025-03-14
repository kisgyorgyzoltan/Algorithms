/*
 * Kisgyörgy Zoltán, 532
 * L3 - 4. Adott egy 𝑛 arab szám, írjuk ki római számjegyekkel!
 */

#include <iostream>
#include <string>

#include <fstream>

using namespace std;

void romaiba(int n, string &s)
{
    int szamjegyek[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string szjek[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int i = 12;
    while (n > 0)
    {
        int h = n / szamjegyek[i];
        n = n % szamjegyek[i];
        while (h--)
        {
            s += szjek[i];
        }
        i--;
    }
}

int main()
{
    int n;
    ifstream f("2149_3_4_3.in");
    // cin >> n;
    f >> n;
    f.close();
    string s = "";
    romaiba(n, s);
    ofstream g("2149_3_4_3.out");
    cout << s;
    g << s;
    g.close();

    return 0;
}
