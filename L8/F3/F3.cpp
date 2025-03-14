/*
 * Kisgyörgy Zoltán, 532
 * L8-3 Adott 𝑛 dominó. Határozzuk meg a leghosszabb olyan sorozatot, mely
közvetlenül egymás után következő dominókból áll és betartja a dominó játék
szabályait. A dominókat el lehet forgatni 180 fokkal.
 */

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void beolvas(int& n, vector<pair<int, int>>& dominok)
{
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        dominok.push_back(make_pair(a, b));
    }
}

int leghosszabb(int n, vector<pair<int, int>>& dominok)
{
    if (dominok.empty())
    {
        return 0;
    }

   vector<vector<int>> leghosszabb(n + 1, vector<int>(2, -1));
   pair<int, int> elozo, jelenlegi;
   int eredmeny = 1; // legalabb 1 dominobol allo sorozat
   leghosszabb[0][0] = 1; // 1 dominobol allo sorozat
   leghosszabb[0][1] = 1; // 1 forgatott dominobol allo sorozat
   for (int i = 1; i < n; i++)
   {
       jelenlegi = dominok[i];
       elozo = dominok[i - 1];
       if (elozo.second == jelenlegi.first) // egyik sincs forgatva
       {
		   leghosszabb[i][0] = leghosszabb[i - 1][0] + 1;
       }
       if (elozo.first == jelenlegi.first) // elozo forgatva
       {
            leghosszabb[i][0] = max(leghosszabb[i][0], leghosszabb[i - 1][1] + 1);
       }
       if (elozo.second == jelenlegi.second) // jelenlegi forgatva
       {
			leghosszabb[i][1] = max(leghosszabb[i][1], leghosszabb[i - 1][0] + 1);
	   }
       if (elozo.first == jelenlegi.second) // mindketto forgatva
       {
           leghosszabb[i][1] = max(leghosszabb[i][1], leghosszabb[i - 1][1] + 1);
       }
       // ha sehogy sem lehet osszerakni a dominokat
       if (elozo.second != jelenlegi.first && elozo.second != jelenlegi.second && elozo.first != jelenlegi.first && elozo.first != jelenlegi.second)
       {
		   leghosszabb[i][0] = 1;
		   leghosszabb[i][1] = 1;
	   }
       eredmeny = max(eredmeny, max(leghosszabb[i][0], leghosszabb[i][1])); 
   }

   return eredmeny;
}
int main()
{
    vector<pair<int, int>> dominok;
    int n, eredmeny;
    beolvas(n, dominok);
    eredmeny = leghosszabb(n, dominok);
    cout << eredmeny;
    return 0;
}