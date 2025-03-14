/*
 * Kisgyörgy Zoltán, 532
 * L8-8 Adott 𝑛 mátrix, melyeket össze lehet szorozni az adott sorrendben. Állapítsuk
meg a szorzásukhoz szükséges skalárszorzatok minimális számát és egy optimális
zárójelezést!
 */

#include <iostream>
#include <limits.h>

using namespace std;

void zarojelek(int i, int j, int** zarojel)
{
    if (i == j) {
        cout << i;
        return;
    }

    cout << "(";

    zarojelek(i, zarojel[i][j], zarojel);

    cout << "x";

    zarojelek(zarojel[i][j] + 1, j, zarojel);
    cout << ")";
}

void matrixSzorzas(int* p, int n)
{
    int** m = new int* [n + 1];

    int** zarojel = new int* [n + 1];

    for (int i = 0; i <= n; i++)
    {
        m[i] = new int[n + 1] {0};
        zarojel[i] = new int[n + 1] {0};
    }

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    zarojel[i][j] = k;
                }
            }
        }
    }

    cout << m[1][n - 1] << endl;
    zarojelek(1, n - 1, zarojel);
    for (int i = 0; i <= n; i++)
    {
        delete[]m[i];
        delete[]zarojel[i];
    }
    delete[]m;
    delete[]zarojel;
}


int main()
{
    int n, s;
    cin >> n;
    int* matrixok = new int[n + 1] {0};
    cin >> matrixok[0];
    for (int i = 1; i < n; i++)
    {
        cin >> matrixok[i] >> s;
    }
    cin >> matrixok[n];
    n++;
    matrixSzorzas(matrixok, n);
    delete[]matrixok;
    return 0;
}