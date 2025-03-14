#include <iostream>
#include <vector>

using namespace std;

constexpr auto d = 11;

void counts(int m, vector<vector<long>> &elek,int hatvany)
{
    vector<vector<long>> seged(m + 1, vector<long>(4,0));
    vector<int> db(10, 0);
    for (int i = 1; i <= m; i++)
    {
        db[(elek[i][3] / hatvany) % 10]++;
    }

    for (int i = 1; i <= 9; i++)
    {
        db[i] += db[i - 1];
    }

    for (int i = m; i >= 1; i--)
    {
        seged[db[(elek[i][3] / hatvany) % 10]][1] = elek[i][1];
        seged[db[(elek[i][3] / hatvany) % 10]][2] = elek[i][2];
        seged[db[(elek[i][3] / hatvany) % 10]][3] = elek[i][3];
        db[(elek[i][3] / hatvany) % 10]--;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            elek[i][j] = seged[i][j];
        }
    }
}

void radix(int m, vector<vector<long>> &elek)
{
    int hatvany = 1;
    for (int i = 0; i < d; i++)
    {
        counts(m, elek, hatvany);
        hatvany *= 10;
    }
}

void hozzafuz(int n,vector<vector<long>> &feszitofa, vector<vector<long>> elek, long j)
{
    int i = 1;
    while (feszitofa[i][1] !=0 && i < n)
    {
        i++;
    }
    feszitofa[i][1] = elek[j][1];
    feszitofa[i][2] = elek[j][2];
    feszitofa[i][3] = elek[j][3];
}

void kruskal(int m, int n, vector<vector<long>> elek, vector<int> komp, long osszeg)
{
    vector<vector<long>> feszitofa;
    feszitofa.push_back(elek[1]); // azert hogy 1-tol legyen az indexeles
    radix(m, elek);
    int i = 0,j = 1,id;
    while ((j<=m) && (i<n-1))
    {
        if (komp[elek[j][1]] != komp[elek[j][2]])
        {
            i++;
            id = komp[elek[j][2]];
            osszeg += elek[j][3];
            //hozzafuz(n,feszitofa,elek,j);
            feszitofa.push_back(elek[j]);
            for (int k = 1; k <= n; k++)
            {
                if (komp[k] == id)
                {
                    komp[k] = komp[elek[j][1]];
                }
            }
        }
        j++;
    }
    cout << "feszitofa:" << endl;
    for (int i = 1; i <= n-1; i++)
    {
        cout << feszitofa[i][1] << " " << feszitofa[i][2] << " " << feszitofa[i][3] << endl;
    }

}

int main()
{
    int n, m;
    long osszeg = 0;
    cin >> n >> m;
    vector<int> komp(n+1, 0);
    vector<vector<long>> elek(m+1,vector<long>(4,0));

    for (int i = 1; i <= n; i++)
    {
        komp[i] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> elek[i][1] >> elek[i][2] >> elek[i][3];
    }

    kruskal(m, n, elek, komp, osszeg);

    return 0;
}