#include <iostream>
#include <vector>

using namespace std;

void busz(int n, vector<int> koord, vector<int>& megoldas,int x)
{
    int tav = 0, ujtav;
    for (int i = 2; i <= n; i++)
    {
        ujtav = tav + koord[i] - koord[i - 1];
        if (ujtav >= x)
        {
            tav = 0;
            megoldas.push_back(koord[i]);
        }
        else
        {
            tav = ujtav;
        }
    }
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> koord(n+1) , megoldas;
    for (int i = 1; i <= n; i++)
    {
        cin >> koord[i];
    }
    busz(n, koord, megoldas,x);
    for (int i = 0; i < megoldas.size(); i++)
    {
        cout << megoldas[i] << " ";
    }
    return 0;
}