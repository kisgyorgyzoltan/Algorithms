#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define vegtelen INT_MAX

void init(int n, vector<vector<int>> a, int s, vector<bool> &ismeretlen, vector<int> &d, vector<int> &p)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = a[s][i];
        ismeretlen[i] = true;
        p[i] = s;
    }
    d[s] = 0;
    ismeretlen[s] = false;
}

int dmin(int n, vector<bool> ismeretlen, vector<int> d, int& ind)
{
    int min = vegtelen;
    for (int j = 1; j <= n; j++)
    {
        if (ismeretlen[j])
        {
            if (d[j] < min)
            {
                min = d[j];
                ind = j;
            }
        }
    }
    return min;
}

void dijkstra(vector<vector<int>> elek, int n, int m, int s)
{
    vector<int> d(n + 1), p(n + 1); 
    vector<bool> ismeretlen(n + 1);
    init(n, elek, s, ismeretlen, d, p);
    // dijkstra resz
    int ind;
    while (dmin(n,ismeretlen,d,ind) < vegtelen)
    {
        ismeretlen[ind] = false;
        for (int j = 1; j <= n; j++)
        {
            if (ismeretlen[j] && (elek[ind][j] < vegtelen))
            {
                int dd = d[ind] + elek[ind][j];
                if (dd<d[j])
                {
                    d[j] = dd;
                    p[j] = ind;
                }
            }
        }
    }

    cout << "d:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
    cout << "p: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << p[i] << " ";
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> elek(n + 1, vector<int>(n + 1, vegtelen));
    for (int i = 1; i <= m; i++)
    {
        int u, v, s;
        cin >> u >> v >> s;
        elek[u][v] = s;
    }
    dijkstra(elek, n, m, 1);

    return 0;
}