/*
* Kisgyörgy Zoltán, 532
* L1 - 6.
* Adott három 64-bites valós szám (double): 𝑎, 𝑏, 𝑐. Képezhetik-e ezek
    a számok egy háromszög oldalait? Ha igen, határozzuk meg és írjuk ki a
    háromszögbe írt, illetve a háromszög köré írt kör sugarát! Ha nem, írjunk ki
    -1-et!
    A hárömszögbe írt és háromszög köré írt körök sugarai és az ezek kiszámításához
    szükséges kifejezések minden részkifejezése ábrázolható 64-bites valósként.
*/

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    if (a < b + c && c < a + b && b < a + c)
    {
        double p = (a + b + c) / 2, T, r, R;
        T = sqrt(p * (p - a) * (p - b) * (p - c));
        r = (2 * T) / (a + b + c);
        R = (a * b * c) / (4 * T);
        cout << setprecision(4) << r << " " << R << endl;
    }
    else
    {
        cout << "-1\n";
    }
    
    return 0;
}
