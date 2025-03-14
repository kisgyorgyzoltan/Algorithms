/*
* Kisgyörgy Zoltán, 532
* L1 - 2.
* Hasonlítsuk össze egy ismétlődő ciklus sebességét amely a beolvasott szám
    gyökéig megy el, háromféleképpen implementálva:
*/
#include <iostream>
#include <time.h>
#include <math.h>

#define K 1000000

using namespace std;

int whilegyok(unsigned long long n)
{
    int i = 0;
    while (i * i <= n)
    {
        i++;
    }
    if (i * i != n)
    {
        i--;
    }

    return i;
}

int sqrtgyok(unsigned long long n)
{
    int i = 0;
    double gyok = sqrt(n);
    while (i <= gyok)
    {
        i++;
    }
    if (i > gyok)
    {
        i--;
    }
    return i;
}
int gyoksqrt(unsigned long long n)
{
    int i = 0;
    while (i <= sqrt(n))
    {
        i++;
    }
    if (i > sqrt(n))
    {
        i--;
    }
    return i;
}

double teszt(unsigned long long n, int(*f) (unsigned long long), unsigned long long& s)
{
    double t;
    clock_t kezd, vege;
    kezd = clock();
    for (int i = 0; i < K; i++)
    {
        s = f(n);
    }
    vege = clock();
    t = (double)(vege - kezd) / CLOCKS_PER_SEC;
    return t;
}

int main()
{
    unsigned long long n, s;
    double t1, t2, t3;
    cin >> n;

    t1 = teszt(n, whilegyok, s);
    t2 = teszt(n, sqrtgyok, s);
    t3 = teszt(n, gyoksqrt, s);

    cerr << t1 << endl;
    cerr << t2 << endl;
    cerr << t3 << endl;

    return 0;
}
