/*
 * Kisgyörgy Zoltán, 532
 * L4-4 Rendezzünk egy 𝑛 elemű tömböt a leszámláló rendezés azon változatával,
melyre nem értelmezhető, hogy stabil-e vagy sem!
 */

#include <iostream>

using namespace std;

constexpr auto K = 1000001;

void stabilcs(int n, long long*& a)
{
    int max = a[1];
    for (int i = 2; i <= n; i++)
        if (a[i] > max)
        {
            max = a[i];
        }
    int* count = new int[max + 1];
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        count[a[i]]++;
    }
    int k = 1;
    for (int i = 0; i <= max; i++)
    {
        for (int j = 1; j <= count[i]; j++)
        {
            a[k++] = i;
        }
    }
    delete[] count;
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
    stabilcs(n, a);
    kiir(n, a);
    delete[]a;
    return 0;
}
