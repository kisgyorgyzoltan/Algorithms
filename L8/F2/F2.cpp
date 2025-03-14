/*
 * Kisgyörgy Zoltán, 532
 * L8-2 Számoljátok ki 𝑛 elem 𝑘-ad rendű kombinációinak számát feljegyzéses módszerrel!
 */

#include <iostream>
#include <vector>

using namespace std;

long long kombi(int n, int k)
{
    vector<vector<long long>> m(n + 1, vector<long long>(k + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
            {
                m[i][j] = 1;
            }
            else {
                m[i][j] = m[i - 1][j - 1] + m[i - 1][j];
            }
        }
    }
    return m[n][k];
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << kombi(n, k);
    return 0;
}
