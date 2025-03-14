/*
 * Kisgyörgy Zoltán, 532
 * L4-10 Írjunk rekurzív algoritmust, amely meghatározza egy adott 𝑎 szám négyzetgyökét, felhasználva a következő sorozatot, melyről tudjuk, hogy √
𝑎-hoz
konvergál.
 */

#include <iostream>
#include <iomanip>

using namespace std;

double gyok(double a, double x, double x0) {
	if (x == x0) {
		return x;
	}
	return gyok(a, (x + a / x) / 2, x);
}

int main()
{
	unsigned long long a;
	cin >> a;
	cout << fixed << setprecision(6) << gyok(a, a, 0) << endl;
	
	return 0;
}
