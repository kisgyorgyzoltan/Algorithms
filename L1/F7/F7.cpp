/*
* Kisgyörgy Zoltán, 532
* L1 - 7.
* Írjunk algoritmust az 𝑎𝑥2+𝑏𝑥+𝑐 = 0 valós együtthatójú egyenlet megoldására!
    Az együtthatók 128-bites valós számok (long double). Garantált, hogy a 𝑏^2−4𝑎𝑐
    kifejezés és annak minden részkifejezése is ábrázolható 128-bites valós számként.
*/

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    long double a, b, c, d, x1, x2;

    cin >> a >> b >> c;
    
    d = (b * b) - 4 * a * c;

    if (d > 0 && a != 0)
    {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);

        if (x1 < x2)
        {
            cout << setprecision(1) << fixed << x1 << " " << x2 << endl;
        }
        else
        {
            cout << setprecision(1) << fixed << x2 << " " << x1 << endl;
        }
    }
    else
    {
        string errmsg = "Nincs ket gyok ";
        if (a==0)
        {
			errmsg += "mert a = 0";
        }
		if (d <= 0)
		{
			errmsg += ", d <= 0";
		}
		errmsg += "\n";
        cerr << errmsg;
    }
    
    return 0;
}
