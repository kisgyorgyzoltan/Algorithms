/*
* Kisgyörgy Zoltán, 532
* L1 - 5.
* Számítsuk ki, adott 𝑛 és 𝑥 értékekre, a következő összeget: 
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n = 0;
    double x = 0, k = 1;
    cin >> n >> x;
	
    double s = 1;
    for (int i = 0; i < n; i++)
    {
        k = k * ((x * x) / (((2 * i) + 1) * ((2 * i) + 2)));
        if (i % 2 == 0)
        {
            s -= k;
        }
        else
        {
            s += k;
        }
    }

    cout << setprecision(3) << s << endl;

    return 0;
}