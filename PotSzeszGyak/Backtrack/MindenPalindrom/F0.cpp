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

void backtrack(string s, vector<string>& v, int k, int n) {
    if (k == n) {
        for (int j = 0; j < v.size(); j++) {
            cout << v[j] << " ";
        }
        cout << endl;
    }
    else {
        for (int j = k; j <= n - 1; j++) {
            string t = s.substr(k, j - k + 1);
            if (palindrom_e(t)) {
                v.push_back(t);
                backtrack(s, v, j + 1, n);
                v.pop_back();
            }
        }
    }
}

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<string> v;
    backtrack(s, v, 0, n);


    return 0;
}