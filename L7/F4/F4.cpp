/*
 * Kisgyörgy Zoltán, 532
 * L7-4 Adott a Hanoi-tornyok feladata, ahol az 1-es rúdról kell a 3-as rúdra átpakoljunk 𝑛 korongot, a 2-es rúd segítségével. Oldjuk meg a feladatot abban
az esetben, ha a 1-es rúdról a 3-as rudra nem szabad direkt módon korongot
mozgatni.
 */

#include <iostream>
#include <string>

using namespace std;

void hanoi(int n, int honnan, int hova, int seged)
{
	if (n >= 1 && honnan != 2 && hova != 2)
	{
		hanoi(n - 1, honnan, hova, seged);
		cout << honnan << " " << seged << endl;
		hanoi(n - 1, hova, honnan, seged);
		cout << seged << " " << hova << endl;
		hanoi(n - 1, honnan, hova, seged);
	}
	else if (n >= 1 && (honnan == 2 || hova == 2))
	{
		hanoi(n - 1, honnan, seged, hova);
		cout << honnan << " " << hova << endl;
		hanoi(n - 1, seged, hova, honnan);
	}
}

int main()
{
	int n;
	cin >> n;
	hanoi(n, 1, 3, 2);

	return 0;
}