/*
 * Kisgyörgy Zoltán, 532
 * L4-1 Rendezzünk egy 𝑛 elemű tömböt koktélrendezéssel!
 */

#include <iostream>

using namespace std;

void koktelr(int n, long long*& a)
{
    int rb = 1, rj = n - 1, j, b;
    bool rendben = false;
    do
    {
        rendben = true;
        j = 0;
        for (int i = rb; i <= rj; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                rendben = false;
                j = i;
            }
        }
        if (!rendben)
        {
            rj = j;
            rendben = true;
            b = n;
            for (int i = rj; i >= rb; i--)
            {
                if (a[i] > a[i + 1])
                {
                    swap(a[i], a[i + 1]);
                    rendben = false;
                    b = i;
                }
            }
            rb = b;
        }
    } while (!rendben);
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
    koktelr(n, a);
    kiir(n, a);
    delete[]a;
    return 0;
}