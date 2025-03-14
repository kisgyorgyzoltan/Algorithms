#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& a, int bal, int kozep, int jobb)
{
    int db = bal - 1, i = bal, j = kozep + 1;
    vector<int> seged(jobb + 1);
    while ((i<=kozep) && (j<= jobb))
    {
        db++;
        if (a[i] < a[j])
        {
            seged[db] = a[i];
            i++;
        }
        else
        {
            seged[db] = a[j];
            j++;
        }
    }

    while (i<=kozep)
    {
        db++;
        seged[db] = a[i];
        i++;
    }
    
    while (j<=jobb)
    {
        db++;
        seged[db] = a[j];
        j++;
    }

    for (int i = bal; i <= jobb; i++)
    {
        a[i] = seged[i];
    }
}

void mergesort(int n, vector<int>& a,int bal, int jobb)
{
    if (bal < jobb)
    {
        int kozep = (bal + jobb) / 2;
        mergesort(n, a, bal, kozep);
        mergesort(n, a, kozep + 1, jobb);
        merge(a, bal, kozep, jobb);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    mergesort(n, a, 1, n);

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}