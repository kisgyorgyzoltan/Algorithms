/*
* Kisgyörgy Zoltán, 532
* L2 - 4. Adott egy csoport év végi vizsgajegyeinek listája. Töröljük ki az 5-ösnél
    kisebb jegyeket a listából. A módósítást a beolvasott tömbben kell elvégezni,
    nem elég csak kiíratni az eredményt.
*/

#include <iostream>
#include <vector>

using namespace std;

void torol(vector<double>& jegyek, int& n)
{
    for (int i = 0; i < n; i++)
    {
        if (jegyek[i] < 5)
        {
            jegyek[i] = jegyek[n - 1];
            n--;
            i--;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<double> jegyek = vector<double>(n);
    for (int i = 0; i < n; i++)
    {
        cin >> jegyek[i];
    }

    torol(jegyek, n);

    for (int i = 0; i < n; i++)
    {
        cout << jegyek[i] << " ";
    }

    return 0;
}
