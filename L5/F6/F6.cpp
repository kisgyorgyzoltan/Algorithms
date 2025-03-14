/*
 * Kisgyörgy Zoltán, 532
 * L5-6 Egy 𝑛 × 𝑛 méretű sakktáblán az (𝑥, 𝑦) pozíción található egy futár és az
(𝑥0, 𝑦0) pozíción egy ló. A lónak el kell jutnia erről a helyről az (𝑥1, 𝑦1) pozícióra,
anélkül, hogy egy bizonyos négyzetre többször lépne illetve, hogy olyan helyen
állna meg, ahonnan a futár kiütheti. Írjuk ki, hogy hányféleképpen lehetséges ez!
 */

#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<vector<char>>& volt, int n, int lox, int loy, int fx, int fy, int celx, int cely, int& db)
{
	if (lox < 1 || lox > n || loy < 1 || loy > n || volt[lox][loy] == 1) // kilépett a tábláról vagy volt már ott
	{
		return;
	}
	if (lox == celx && loy == cely) // a ló elérte a célt
	{
		db++;
		return;
	}
	if (lox == fx && loy == fy) // a ló és a futár egy helyen vannak
	{
		return;
	}
	if (abs(fx - lox) == abs(fy - loy) || fx + fy == lox + loy) // a futár kiütheti a lovat
	{
		return;
	}

	volt[lox][loy] = 1;
	backtrack(volt, n, lox + 2, loy + 1, fx, fy, celx, cely, db);
	backtrack(volt, n, lox + 2, loy - 1, fx, fy, celx, cely, db);
	backtrack(volt, n, lox - 2, loy + 1, fx, fy, celx, cely, db);
	backtrack(volt, n, lox - 2, loy - 1, fx, fy, celx, cely, db);
	backtrack(volt, n, lox + 1, loy + 2, fx, fy, celx, cely, db);
	backtrack(volt, n, lox + 1, loy - 2, fx, fy, celx, cely, db);
	backtrack(volt, n, lox - 1, loy + 2, fx, fy, celx, cely, db);
	backtrack(volt, n, lox - 1, loy - 2, fx, fy, celx, cely, db);

	// visszalépés
	volt[lox][loy] = 0;
}

int main()
{
	int n, lox, loy, fx, fy, celx, cely, db = 0;
	cin >> n >>	fx >> fy >> lox >> loy >> celx >> cely;

	vector<vector<char>> volt(n + 1, vector<char>(n + 1, 0));
	volt[lox][loy] = 2; // a ló kiiindulási helye
	backtrack(volt, n, lox, loy, fx, fy, celx, cely, db);
	cout << db << endl;
	return 0;
}
