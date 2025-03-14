#include <iostream>
#include <vector>

using namespace std;

void kiir(vector<int> darab, int meddig, vector<int> b)
{
    for (int i = 1; i <= meddig; i++)
    {
        cout << b[i] << " : " << darab[i] << endl;
    }
    cout << endl;
}

void bankjegy(vector<int> darab, int k, int sum, vector<int> b, int n)
{
    if (k == n)
    {
        if ((sum % b[n]) == 0)
        {
            darab[n] = sum / b[n];
            kiir(darab, n, b);
        }
        else
        {
            for (darab[k] = 0; darab[k] <= sum / b[k]; darab[k]++)
            {
                int maradt = sum - darab[k] * b[k];
                if (maradt == 0)
                {
                    kiir(darab, k, b);
                }
                else
                {
                    bankjegy(darab, k + 1, maradt, b, n);
                }
            }
        }
    }
}

int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> b(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    vector<int> darab(n+1,0);
    bankjegy(darab, 1, s, b, n);
    return 0;
}