/*
* Kisgyörgy Zoltán, 532
* L1 - 4.
* Számítsuk ki egy háromszög területét, ha ismerjük oldalainak a hosszát!
    Az oldalak hosszai 64-bites valós számok (double). A háromszög területe és
    a számítások során megjelenő részkifejezések mindegyike ábrázolható 64-bites
    valósként.
*/

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    double a, b, c, p, T;
    cin >> a >> b >> c;
    if (a + b > c && a + c > b && b + c > a) 
    {
        p = (a + b + c) / 2;
        T = sqrt(p * (p - a) * (p - b) * (p - c));
        cout << setprecision(5) << T << endl;
    }
    return 0;
}
