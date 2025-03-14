/*
 * Kisgyörgy Zoltán, 532
 * L5-4 Bontsunk fel egy szót minden lehetséges módon palindromszavakra!
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool palindrom_e(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

void backtrack(string s, vector<string>& v, int i) {
    if (i == s.size()) {
        for (int j = 0; j < v.size(); ++j) {
            cout << v[j] << " ";
        }
        cout << endl;
    }
    else {
        for (int j = i; j < s.size(); j++) {
            string t = s.substr(i, j - i + 1);
            if (palindrom_e(t)) {
                v.push_back(t);
                backtrack(s, v, j + 1);
                v.pop_back();
            }
        }
    }
}

int main() {
    int hossz;
    string s;
    cin >> hossz;
    cin >> s;
    vector<string> v;
    if (hossz == s.length())
    {
        backtrack(s, v, 0);
    }

    return 0;
}