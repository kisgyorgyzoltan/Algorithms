#include <iostream>
#include <vector>

using namespace std;

int sumv(vector<int> v)
{
    int s = 0;
    for (int i = 1; i < v.size(); i++)
    {
        s += v[i];
    }
    return s;
}

void kiirv(vector<int> v, int n , int meddig)
{
    cout << n << " = ";
    for (int i = 1; i < meddig; i++)
    {
        cout << v[i] << " + ";
    }
    cout << v[meddig] << endl;
}

void particiok(vector<int> v, int k, int s, int n)
{
    for (int i = 1; i <= s; i++)
    {
        v[k] = i;
        if (i < s)
        {
            particiok(v, k + 1, s - i, n);
        }
        else
        {
            kiirv(v, n, k);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n+1);
    particiok(v, 1, n, n);
    return 0;
}