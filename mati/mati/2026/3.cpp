#include "bits/stdc++.h"
// #define int long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e3 + 10;

// vi arr;

// void discreate() {
//     sort(arr.begin(), arr.end());
//     arr.erase(unique(arr.begin(), arr.end()), arr.end());
// }

// int quary(int x) {
//     return lower_bound(arr.begin(), arr.end(), x) - arr.begin() + 1;
// }

void solve() {
    int n;
    cin >> n;
    vi lx(n), ly(n), rx(n), ry(n);
    for (int i = 0; i < n; i++) {
        cin >> lx[i] >> ly[i] >> rx[i] >> ry[i];
    }

    for (int i = 0; i < n; i++) {
        int ans = 0;
        // cout << i << ":";
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (rx[j] < lx[i] || lx[j] > rx[i] || ly[j] > ry[i] ||
                ry[j] < ly[i]) {
                continue;
            } else {
                ans++;
                // cout << j << ' ';
            }
        }
        // cout << endl;
        cout << ans << ' ';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}