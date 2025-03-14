/*
 * Kisgyörgy Zoltán, 532
 * L6-9 Legyen két számsorozat 𝐴 = [𝑎1, 𝑎2, . . . , 𝑎𝑚] és 𝐵 = [𝑏1, 𝑏2, . . . , 𝑏𝑛]. Válasszuk
ki a 𝐵 sorozatból azon 𝑋 = [𝑥1, 𝑥2, . . . , 𝑥𝑚] elemeket, amelynek megfelelően az
𝐸 = 𝑎1𝑥1 + 𝑎2𝑥2 + . . . + 𝑎𝑚𝑥𝑚 kifejezés értéke a lehető legnagyobb.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int m, n;
	cin >> m;
	vector<long> A(m);
	for (int i = 0; i < m; ++i)
		cin >> A[i];
	cin >> n;
	vector<long> B(n);
	for (int i = 0; i < n; ++i)
		cin >> B[i];
	long long maxOsszeg = 0;

	sort(A.begin(), A.end(), [](long a, long b) { return a > b; }); // csökkenő sorrendbe rendezés
	sort(B.begin(), B.end(), [](long a, long b) { return a > b; }); // csökkenő sorrendbe rendezés

	for (int i = 0; i < m; ++i)
	{
		if (A[i] == 0) continue; // ha nulla akkor nem szorozom semmivel
		else if (A[i] > 0) // ha A legnagyobb eleme pozitív akkor a B legnagyobb elemével szorzom
		{
			long bMax = B[0];

			maxOsszeg += A[i] * bMax;

			// torlom az elso elemet
			B.erase(B.begin());
		}
		else // ha A legnagyobb eleme negatív akkor a B legkisebb elemével szorzom
		{
			long bMin = B[B.size() - 1];
			maxOsszeg += A[i] * bMin;
		}
	}
	cout << maxOsszeg << endl;
	return 0;
}
