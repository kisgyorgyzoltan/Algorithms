#include <iostream>
#include <vector>

using namespace std;

int lomuto(vector<int>& a, int bal, int jobb)
{
    int strazsa = a[jobb];
    int i = bal - 1;
    for (int j = bal; j <= jobb - 1; j++)
    {
        if (a[j] <= strazsa)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[jobb]);
    return (i + 1);
}

int hoare(vector<int> &a, int bal, int jobb)
{
    int strazsa = a[bal];
    int i = bal - 1, j = jobb + 1;
    while (true)
    {
        do
        {
            i++;
        } while (a[i] < strazsa);
        
        do
        {
            j--;
        } while (a[j] > strazsa);

        if (i>=j)
        {
            return j;
        }
        swap(a[i], a[j]);
    }
}

void qsrt(vector<int> &a, int bal, int jobb)
{
    if (bal < jobb)
    {
        // HOARE
        //int m = hoare(a,bal,jobb);
        //qsrt(a, bal, m);
        //qsrt(a, m + 1, jobb);

        // LOMUTO
        int m = lomuto(a, bal, jobb);
        qsrt(a, bal, m - 1);
        qsrt(a, m + 1, jobb);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    qsrt(a, 1, n);

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}