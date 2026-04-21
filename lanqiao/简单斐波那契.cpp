#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;

int n;

void solve() {
    cin >> n;
    int a[n];
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i < n; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}