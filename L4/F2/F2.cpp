/*
 * Kisgyörgy Zoltán, 532
 * L4-2 Rendezzünk egy 𝑛 elemű tömböt minimumkiválasztásra épülő rendezéssel!
 */

#include <iostream>

using namespace std;

void minr(int n, long long*& a)
{
    for (int i = 1; i < n; i++)
    {
        int index = i;
        for (int j = i + 1; j <= n; j++)
        {
            if (a[index] > a[j])
            {
                index = j;
            }
        }
        swap(a[index], a[i]);
    }
}

void beolvas(int& n, long long*& a)
{
    cin >> n;
    a = new long long[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

void kiir(int n, long long* a)
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << "\n";
    }
}

int main()
{
    int n;
    long long* a;
    beolvas(n, a);
    minr(n, a);
    kiir(n, a);
    delete[]a;
    return 0;
}