/*
* Kisgyörgy Zoltán, 532
* L2 - 8.
* Vizsgáljuk meg, hogy egy adott, 𝑛×𝑛 méretű négyzetes tömb bűvös négyzet-e
    vagy sem. Egy természetes számokkal feltöltött négyzetes tömböt akkor nevezünk
    bűvös négyzetnek, ha páronként különböző számokat tartalmaz, a számok összege
    soronként és oszloponként, valamint a két átló mentén azonos. Alkalmazzuk a
    Halmaz-e programozási tételt!
*/

#include <iostream>

using namespace std;

void beolvas(int& n, unsigned long long**& matrix)
{
    cin >> n;
    matrix = new unsigned long long* [n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new unsigned long long[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

bool halmaze(int n, unsigned long long** matrix) //megnezi hogy a matrix elemei halmazt alkotnak-e
{
    bool halmaz = true;
    int i = 0;
    int j = 0;
    int k = i;
    int l = j + 1;

    for (i = 0; i < n; i++)
    {
        k = i;
        for (j = 0; j < n; j++)
        {
            l = j + 1;
            while (k < n)
            {
                while (l < n)
                {
                    if (matrix[i][j] == matrix[k][l])
                    {
                        halmaz = false;
                        l = n;
                        k = n;
                        j = n;
                        i = n;
                    }
                    l++;
                }
                k++;
                l = 0;
            }
        }
    }
    return halmaz;
}
bool osszegek(int n, unsigned long long int** matrix) //megnezi hogy a szukseges osszegek azonosak-e
{
    unsigned long long int oszl = 0, sor = 0, atlo1 = 0, atlo2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sor += matrix[i][j];
            oszl += matrix[j][i];
            atlo1 += matrix[i][i];
            atlo2 += matrix[i][n - i - 1];

        }
    }
    return((sor == oszl) && (oszl == atlo1) && (atlo1 == atlo2));
}

int main()
{
    int n;
    unsigned long long** matrix;
    beolvas(n, matrix);

    if (halmaze(n, matrix) && osszegek(n, matrix))
    {
        cout << "igen" << endl;
    }
    else
    {
        cout << "nem " << endl;
    }

    return 0;
}