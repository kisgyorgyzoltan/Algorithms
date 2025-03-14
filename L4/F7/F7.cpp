/*
 * Kisgyörgy Zoltán, 532
 * L4-7 Írjunk rekurzív algoritmust, amely kiszámítja egy 𝑛-ed fokú polinom értékét
egy adott valós 𝑥 pontban! Ne használjunk ismétlő struktúrát a beolvasáson
kívül!
 */

#include <iostream>

using namespace std;

double hatvany(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }

    double alap = x, eredmeny = 1;
    int kitevo = n;
    for (int i = 0; i < n; i++)
    {
        if (kitevo % 2 == 1)
        {
            eredmeny *= alap;
        }
        alap *= alap;
        kitevo /= 2;
    }
    return eredmeny;
}

double polinom(int *k, int n, double x)
{
    if (n == 0)
    {
        return k[0];
    }
    else
    {
        return k[n] * hatvany(x, n) + polinom(k, n - 1, x);
    }
}

void beolvas(int &n, double &x, int *&k)
{
    cin >> n;
    k = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        cin >> k[i];
    }
    cin >> x;
}

int main()
{
    int *k, n;
    double x;
    beolvas(n, x, k);
    cout << polinom(k, n, x);

    delete[] k;
    return 0;
}