/*
* Kisgyörgy Zoltán, 532
* L2 - 10.
* Adott a következő sorozat, amelynek minden elemét – az elsőt kivéve – az
    előző elem segítségével generáljuk: 1, 11, 21, 1211, 111221, . . .
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string to_string(int num)
{
    stringstream ss;
    ss << num;
    return ss.str();
}

void general(int n)
{
	string jelenlegi = "1", eredmeny;
    for (int i = 0; i < n; i++)
    {
        eredmeny = "";
		int j = 0, hossz = jelenlegi.length();
        while (j < hossz)
        {
            int db = 1;

            while ((j + 1 < hossz) && jelenlegi[j] == jelenlegi[j + 1])
            {
                j++;
                db++;
            }
			string dbstring = std::to_string(db);
            eredmeny = eredmeny + dbstring + jelenlegi[j];
            j++;
        }
		jelenlegi = eredmeny;
    }
	cout << jelenlegi << endl;
}

int main()
{
    int n;;
    cin >> n;
    general(n-1);
    return 0;
}
