#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void autok(int n, vector<pair<int,int>> a, vector<pair<int, int>>& megoldas)
{
    sort(a.begin(), a.end(), comparator);
    megoldas.push_back(a[1]);
    pair<int, int> utolso = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (utolso.second <= a[i].first)
        {
            megoldas.push_back(a[i]);
            utolso = a[i];
        }
    }
}

int main()
{
    int n;
    cin >> n ;
    vector<pair<int, int>> koord(n + 1), megoldas;
    for (int i = 1; i <= n; i++)
    {
        cin >> koord[i].first >> koord[i].second;
    }
    autok(n, koord, megoldas);
    for (int i = 0; i < megoldas.size(); i++)
    {
        cout << megoldas[i].first << " " << megoldas[i].second << endl;
    }
    return 0;
}