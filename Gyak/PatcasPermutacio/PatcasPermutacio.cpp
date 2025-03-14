#include <iostream>
#include <vector>

using namespace std;
    
bool folytat(vector<int> v, int k)
{
    for (int i = 1; i <= k-1; i++)
    {
        if (v[i] == v[k])
        {
            return false;
        }
    }
    return true;
}

void permut(vector<int> v, int k, int n)
{
    if (k == n+1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (v[k] = 1; v[k] <= n; v[k]++)
        {
            if (folytat(v,k))
            {
                permut(v, k + 1,n);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n+1);
    permut(v, 1, n);
    return 0;
}