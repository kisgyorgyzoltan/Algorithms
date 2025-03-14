#include <iostream>
#include <vector>

using namespace std;

void kiir(vector<int> v, int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void descartes(vector<int> v, int k, int n, int m)
{
    if (k == n + 1)
    {
        kiir(v, n);
    }
    else
    {
        for (v[k] = 1; v[k] <= m; v[k]++)
        {
            descartes(v, k + 1, n, m);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    descartes(v, 1, n, m);
    return 0;
}
