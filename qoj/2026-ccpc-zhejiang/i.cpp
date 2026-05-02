#include "bits/stdc++.h"

#define int long long
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

int n, m;

void solve() {
    cin >> n >> m;
    vi a[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    for (int i = 0; i < n; i++) {
        sort(a[i].begin(), a[i].end());
    }
    vector<vector<int>> b(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[j][i] = a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        sort(b[i].begin(), b[i].end());
    }
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += b[i][0];
    }
    cout << sum << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}