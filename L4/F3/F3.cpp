/*
 * Kisgyörgy Zoltán, 532
 * L4-3 Rendezzünk egy 𝑛 elemű tömböt beszúró rendezéssel!
 */

#include <iostream>

using namespace std;

void beszr(int n, long long*& a)
{
    for (int i = 2; i <= n; i++)
    {
        long long seged = a[i];
        int j = i - 1;
        while ((j >= 1) && a[j] > seged)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = seged;
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
    beszr(n, a);
    kiir(n, a);
    delete[]a;
    return 0;
}