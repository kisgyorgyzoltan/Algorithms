/*
* Kisgy�rgy Zolt�n, 532
* L2 - 4. Adott egy csoport �v v�gi vizsgajegyeinek list�ja. T�r�lj�k ki az 5-�sn�l
    kisebb jegyeket a list�b�l. A m�d�s�t�st a beolvasott t�mbben kell elv�gezni,
    nem el�g csak ki�ratni az eredm�nyt.
*/

#include <iostream>
#include <vector>
#include <fstream>

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
    ifstream f("2149_2_4_3.in");
    f >> n;
    vector<double> jegyek = vector<double>(n);
    for (int i = 0; i < n; i++)
    {
        f >> jegyek[i];
    }
    f.close();
    torol(jegyek, n);
    ofstream g("2149_2_4_3.out");
    for (int i = 0; i < n; i++)
    {
        g << jegyek[i] << " ";
    }
    g.close();

    return 0;
}
