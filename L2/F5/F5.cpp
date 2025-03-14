/*
* Kisgyörgy Zoltán, 532
* L2 - 5. Adott 𝑛 programozó fizetése. Válogassuk szét őket a fizetésük alapján. Az
    első csoportba azok kerülnek, akiknek a fizetésük nagyobb mint 1000 EUR, a
    másodikba a megmaradtak közül azok, akiknek a fizetése nagyobb mint 700
    EUR, a harmadikban maradnak a többiek (a sorrend nem fontos). Dolgozzunk
    egyetlen tömbbel és végezzük el abban a szétválogatást, nem elég a kiíratásban
    csoportokra osztani a számokat.
*/

#include <iostream>
#include <fstream>

using namespace std;

void beolvas(int& n, int*& fizetesek)
{
    ifstream f("2149_2_5_3.in");
    f >> n;
    fizetesek = new int[n];
    for (int i = 0; i < n; i++)
    {
        f >> fizetesek[i];
    }
    f.close();
}

bool nagyobbmint(int mi, int minel)
{
    return(mi > minel);
}

void szetvalogat(int indul, int n, int* fizetesek, int hasonlit, int& db)
{
    int e = indul, u = n - 1, seged = fizetesek[e];
    while (e < u)
    {
        while ((e < u) && !nagyobbmint(fizetesek[u], hasonlit))
        {
            u--;
        }
        if (e < u)
        {
            fizetesek[e] = fizetesek[u];
            e++;
            while ((e < u) && nagyobbmint(fizetesek[e], hasonlit))
            {
                e++;
            }
            if (e < u)
            {
                fizetesek[u] = fizetesek[e];
                u--;
            }
        }
    }
    fizetesek[e] = seged;
    if (nagyobbmint(fizetesek[e], hasonlit))
    {
        db = e;
    }
    else
    {
        db = e - 1;
    }
}

void kiir(int honnan, int meddig, int* a)
{
    ofstream g("2149_2_5_3.out", ios_base::app);
    for (int i = honnan; i <= meddig; i++)
    {
        g << a[i] << " ";
    }
    g << endl;
}
int main()
{
    int n, f1, f2;
    int* fizetesek;
    beolvas(n, fizetesek);
    szetvalogat(0, n, fizetesek, 1000, f1);
    kiir(0, f1, fizetesek);
    szetvalogat(f1 + 1, n, fizetesek, 700, f2);
    kiir(f1 + 1, f2, fizetesek);
    kiir(f2 + 1, n - 1, fizetesek);
    return 0;
}
