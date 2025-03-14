/*
 * Kisgyörgy Zoltán, 532
 * L4-5 Rendezzünk egy 𝑛 elemű tömböt számjegyes rendezéssel!
 */

#include <iostream>

using namespace std;

constexpr auto MAXDBSZJ = 20;

void kiir(int n, unsigned long long *a)
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << endl;
    }
}

void rcs(int n, unsigned long long *&a, unsigned long long hatvany)
{
    unsigned long long *b = new unsigned long long[n + 1];
    int db[10];
    for (int i = 0; i < 10; i++)
    {
        db[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        int szj = (a[i] / hatvany) % 10;
        db[szj]++;
    }

    for (int i = 1; i < 10; i++)
    {
        db[i] += db[i - 1];
    }

    for (int i = n; i >= 1; i--)
    {
        int szj = (a[i] / hatvany) % 10;
        b[db[szj]] = a[i];
        db[szj]--;
    }

    for (int i = 1; i <= n; i++)
    {
        a[i] = b[i];
    }

    delete[] b;
}

void radix(int n, unsigned long long *&a)
{
    unsigned long long hatvany = 1;
    for (int i = 0; i < MAXDBSZJ; i++)
    {
        rcs(n, a, hatvany);
        hatvany *= 10;
    }
}

void beolvas(int &n, unsigned long long *&a)
{
    cin >> n;
    a = new unsigned long long[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cout << endl;
}

int main()
{
    int n;
    unsigned long long *a;
    beolvas(n, a);
    radix(n, a);
    kiir(n, a);
    delete[] a;
    return 0;
}
