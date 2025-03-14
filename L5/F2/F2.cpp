/*
 * Kisgyörgy Zoltán, 532
 * L5-2. Helyezzünk el 𝑛 darab királynőt egy 𝑛 × 𝑛-es sakktáblán minden lehetséges
módon, úgy, hogy ne üssék egymást. Számoljuk meg, hogy hányféleképpen
lehetséges ez és írassuk ki a megadott sorszámú konfigurációkat a lexikografikus
sorrendet tekintve
 */

#include <iostream>
#include <cstdlib>

using namespace std;

void hamistomb(int n, bool* a)
{
	for (int i = 0; i <= n; i++)
	{
		a[i] = false;
	}
}

void beolvas(int& n, int& q, int*& sorszamok, int*& v, bool*& sor, bool*& atlok, bool*& mellekatlok, int**& megoldasok)
{
	cin >> n >> q;
	v = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		v[i] = 0;
	}
	sorszamok = new int[q + 1];
	for (int i = 1; i <= q; i++)
	{
		cin >> sorszamok[i];
	}

	sor = new bool[n + 1];
	atlok = new bool[2 * n + 1];
	mellekatlok = new bool[2 * n + 1];
	megoldasok = new int* [q + 1];
	for (int i = 0; i <= q; i++)
	{
		megoldasok[i] = new int[n + 1] {0};
	}
	if (q)
	{
		hamistomb(n, sor);
		hamistomb(2 * n, atlok);
		hamistomb(2 * n, mellekatlok);
	}
}

void kiir(int* v, int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j == v[i])
			{
				cout << "Q";
			}
			else
			{
				cout << ".";
			}
		}
		cout << endl;
	}
	cout << endl;
}

bool nemTamad(int i, int atlo_index, int mellekatlo_index, bool* sor, bool* atlok, bool* mellekatlok)
{
	if ((sor[i] == true) || (atlok[atlo_index] == true) || (mellekatlok[mellekatlo_index] == true))
		return false;
	else return true;
}


void tarol(int**& megoldasok, int n, int* v, int dbMegoldas)
{
	for (int i = 1; i <= n; i++)
	{
		megoldasok[dbMegoldas][i] = v[i];
	}
}

bool benneVan(int* a, int k, int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == k)
		{
			return true;
		}
	}
	return false;
}

int indexe(int* a, int k, int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == k)
		{
			return i;
		}
	}
	return -1;
}

void kiralynok(int n, 
			   int* v,
			   int* sorszamok,
			   int q,
			   int k,
			   bool* sor, 
			   bool* atlok,
			   bool* mellekatlok,
			   int**& megoldasok,
			   int& dbOsszesMegoldas, 
			   int& dbMentett
)
{
	int atlo_index, mellekatlo_index;
	
	if (k <= n) // amig k != n + 1 azaz nem raktuk le mind az n darab kiralynot
	{
		for (int i = 1; i <= n; i++)
		{
			v[k] = i; // i. sor k-adik oszlopaba teszunk egy kiralynot
			atlo_index = i - k + n + 1; // ezen az atlo menten tamadhatjak
			mellekatlo_index = i + k + 1; // ezen a mellekatlo menten tamadhatjak
			if (nemTamad(i, atlo_index, mellekatlo_index, sor, atlok, mellekatlok)) // ha lerakhatom
			{
				//felteszek egy kiralynot
				sor[i] = true;
				atlok[atlo_index] = true;
				mellekatlok[mellekatlo_index] = true;

				kiralynok(n, v, sorszamok, q, k + 1, sor, atlok, mellekatlok, megoldasok, dbOsszesMegoldas, dbMentett); // kovetkezo kiralyno
				
				//leveszem a tablarol az utoljara lerakott kiralynot
				sor[i] = false;
				atlok[atlo_index] = false;
				mellekatlok[mellekatlo_index] = false;
			}
		}
	}
	else // Megoldas eseten
	{
		dbOsszesMegoldas++;
		// ha a jelenlegi megoldas sorszama benne van a sorszamok kozott akkor eltarolom
		if (dbMentett <= q && benneVan(sorszamok, dbOsszesMegoldas, q)) 
		{
			int mentesiIndex = indexe(sorszamok, dbOsszesMegoldas, q); // sorszamokban megkeresem a jelenlegi megoldas indexet
			tarol(megoldasok, n, v, mentesiIndex);
			dbMentett++;
		}
	}
}


int main()
{
	int n, q, dbMegoldas = 0, dbMentett = 0;
	int* sorszamok, * v, ** megoldasok;
	bool* sor, * atlok, * mellekatlok;
	beolvas(n, q, sorszamok, v, sor, atlok, mellekatlok, megoldasok);

	kiralynok(n, v, sorszamok, q, 1, sor, atlok, mellekatlok, megoldasok, dbMegoldas, dbMentett);

	if (dbMentett > 0) // volt min. 1 megoldas
	{
		for (int i = 1; i <= q; i++)
		{
			kiir(megoldasok[i], n);
		}
	}

	cout << dbMegoldas;

	delete[]sor;
	delete[]atlok;

	return 0;
}
