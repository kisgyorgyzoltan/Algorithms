/*
* Kisgyörgy Zoltán, 532
* L1 - 1.
* Hasonlítsuk össze két egész típusú változó cseréjének sebességét három különböző módszerrel:
*/

#include <iostream>
#include <time.h>

#define K 500000

using namespace std;

void segedcsere(unsigned& x, unsigned& y)
{
    unsigned s = x;
    x = y;
    y = s;
}

void kivoncsere(unsigned& x, unsigned& y)
{
    x += y;
    y = x - y;
    x -= y;
}

void xorcsere(unsigned& x, unsigned& y)
{
    x = x xor y;
    y = x xor y;
    x = x xor y;
}

int main()
{
    unsigned a, b;
    double t1, t2, t3;
    clock_t kezd, vege;
    cin >> a >> b;

    segedcsere(a, b);
    cout << a << " " << b << endl;

    kezd = clock();
    for (int i = 0; i < K; i++)
    {
        segedcsere(a, b);
    }
    vege = clock();
    t1 = (double)(vege - kezd) / CLOCKS_PER_SEC;


    kezd = clock();
    for (int i = 0; i < K; i++)
    {
        kivoncsere(a, b);
    }
    vege = clock();
    t2 = (double)(vege - kezd) / CLOCKS_PER_SEC;


    kezd = clock();
    for (int i = 0; i < K; i++)
    {
        xorcsere(a, b);
    }
    vege = clock();
    t3 = (double)(vege - kezd) / CLOCKS_PER_SEC;

    cerr << t1 << "\n" << t2 << "\n" << t3;
    return 0;
}