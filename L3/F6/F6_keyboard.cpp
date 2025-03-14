/*
 * Kisgyörgy Zoltán, 532
 * L3 - 6. Keressük meg adott számmal bezárólag a legtöbb osztójú természetes számot!
 */

#include <iostream>

using namespace std;

void legtobboszt(long n)
{
    if (n == 1)
    {
        cout << 1 << " " << 0;
    }
    int* szita = new int[n + 1];
    szita[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        szita[i] = -2;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; j += i)
        {
            szita[j]++;
        }
    }

    int max = 0;
    for (int i = 2; i <= n; i++)
    {
        if (max < szita[i])
        {   
            max = szita[i];
        }
    }

    int i = 2;
    while (i <= n && szita[i] != max)
    {
        i++;
    }
    
	if (i <= n)
	{
		cout << i << " " << max << endl;
	}
	
    delete[] szita;
}
int main()
{
    long n;
    cin >> n;
    if (n >= 1 && n <= 10000000)
    {
        legtobboszt(n);
    }
    return 0;
}