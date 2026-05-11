#include "bits/stdc++.h"
#define int long long

using namespace std;

const int mod = 1e9 + 7;

int qmi(int a, int b, int p) {
    int ans = 1;
    a %= p;
    while (b) {
        if (b & 1)
            ans = (ans * a) % p;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

signed main() {
    int x, y;
    cin >> x >> y;
    vector<int> a, b;
    for (int i = 1; i <= x / i; i++) {
        if (x % i == 0) {
            a.push_back(i);
            a.push_back(x / i);
        }
    }
    for (int i = 1; i <= y / i; i++) {
        if (y % i == 0) {
            b.push_back(i);
            b.push_back(y / i);
        }
    }

    vector<int> c;
    for (int aa : a) {
        for (int bb : b) {
            c.push_back(aa * bb);
        }
    }

    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    //     for (int cc : c){
    //         cout << cc << ' ';
    //     }
    int ans = 0;

    for (int cc : c) {
        ans = (ans + qmi(cc, cc, mod)) % mod;
    }
    cout << ans << endl;

    return 0;
}