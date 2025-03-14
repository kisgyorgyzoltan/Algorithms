#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

void kiirirany(vector<string> iranyok, int k)
{
    for (int i = 1; i <= k; i++)
    {
        cout << iranyok[i] << endl;
    }
    cout << endl;
}

void kiirkoord(vector<pair<int, int>> eredmeny, int k)
{
    for (int i = 1; i <= k; i++)
    {
        cout << eredmeny[i].first << " " << eredmeny[i].second << endl;
    }
    cout << endl;
}

void kiut(int x, int y, int k, vector<pair<int, int>> eredmeny, vector<vector<bool>> volt, vector<vector<int>> labirintus, int n, int m, string irany, vector<string> iranyok) 
{
    if ((labirintus[x][y] == 1) && (volt[x][y] == false)) // lephetek e vagy vissza kell lepni
    {
        volt[x][y] = true;
        eredmeny.push_back(make_pair(x,y));
        iranyok.push_back(irany);
        if (x==1 || x == n || y==1 || y== m) // kiertem
        {
            kiirkoord(eredmeny, k);
            //kiirirany(iranyok, k);
        }
        kiut(x + 1, y, k + 1, eredmeny, volt, labirintus, n, m,"le",iranyok);
        kiut(x - 1, y, k + 1, eredmeny, volt, labirintus, n, m, "fel", iranyok);
        kiut(x, y + 1, k + 1, eredmeny, volt, labirintus, n, m, "jobb", iranyok);
        kiut(x, y - 1, k + 1, eredmeny, volt, labirintus, n, m, "bal", iranyok);
        volt[x][y] = false;
    }
}

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    vector<vector<int>> labirintus(n + 2, vector<int>(m + 2, 0));
    vector<vector<bool>> volt(n + 1, vector<bool>(m + 1, false));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> labirintus[i][j];
        }
    }
    cin >> x >> y;
    cout << endl;
    vector<pair<int, int>> eredmeny;
    vector<string> iranyok;
    eredmeny.push_back(make_pair(x, y));
    iranyok.push_back("");
    kiut(x, y, 1, eredmeny, volt, labirintus, n, m, "",iranyok);
    return 0;
}
