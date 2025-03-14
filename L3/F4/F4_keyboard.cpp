/*
* Kisgyörgy Zoltán, 532
* L3 - 4. Adott egy 𝑛 arab szám, írjuk ki római számjegyekkel!
*/

#include <iostream>
#include <string>

using namespace std;

void romaiba(int n, string& s)
{
    int szamjegyek[] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
    string szjek[] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };
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
    cin >> n;
    string s = "";
    romaiba(n, s);
    cout << s;

    return 0;
}
