/*
 * Kisgyörgy Zoltán, 532
 * L7-1 Legyen a következő játék: az egyik játékos (Játékos1) gondol egy 1 és 1000
közötti természetes számra. A másik játékosnak (Játékos2) ki kell találnia ezt
a számot minél kevesebb próbálgatással. A titkos szám „birtokosa” (Játékos1)
egy-egy találgatásra csak annyit válaszol, hogy a titkos szám kisebb vagy nagyobb
mint a másik játékos (Játékos2) által feltételezett szám.
Írjunk programot amely a fenti játékot szimulálja, úgy, hogy a programunk a
Játékos2, azaz ő találja ki a felhasználó titkos számát.
 */

#include <iostream>

using namespace std;

void talalgat(int bal, int jobb)
{

    int kozep = (bal + jobb) / 2;
    string valasz;
    if (bal == jobb)
    {
        cout << bal << endl;
    }
    else
    {
        cout << kozep << endl;
        cin >> valasz;
        if (valasz == "0" || valasz == "-1" || valasz == "1")
        {
            if (valasz != "0")
            {
                if (valasz == "1")
                {
                    talalgat(kozep + 1, jobb);
                }
                if (valasz == "-1")
                {
                    talalgat(bal, kozep - 1);
                }
            }
        }
    }
}

int main()
{
    talalgat(1, 1000);
    return 0;
}