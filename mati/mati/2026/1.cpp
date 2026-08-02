#include "bits/stdc++.h"

using namespace std;

signed main() {
    string s;
    cin >> s;
    bool suc = true;
    for (char c : s) {
        if (c < 'a' || c > 'z') {
            suc = false;
            break;
        }
    }
    if (suc == true) {
        cout << "Yes" << endl;
        return 0;
    }
    suc = true;
    for (char c : s) {
        if (c < 'A' || c > 'Z') {
            suc = false;
            break;
        }
    }
    if (suc == true) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}