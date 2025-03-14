/*
* Kisgyörgy Zoltán, 532
* L1 - 3.
* Olvassunk be a billentyűzetről három 64-bites előjeles egész számot. Írjuk ki
    őket növekvő sorrendben! 
    Ne rendezzük a számokat, csak írjuk ki a kért sorrendben. 
    Egymás utáni elágazások helyett, egymásba ágyazottakat alkalmazzunk.
*/

#include <iostream>

using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;

    if (a > b)
    {
        if (b > c)
        {
            cout << c << " " << b << " " << a << endl;
        }
        else
        {
            if (a > c)
            {
                cout << b << " " << c << " " << a << endl;
            }
            else
            {
                cout << b << " " << a << " " << c << endl;
            }
        }
    }
    else
    {
        if (a < c)
        {
            if (b < c)
            {
                cout << a << " " << b << " " << c << endl;
            }
            else
            {
                cout << a << " " << c << " " << b << endl;
            }
        }
        else
        {
            cout << c << " " << a << " " << b << endl;        }
    }
    
    return 0;
}
