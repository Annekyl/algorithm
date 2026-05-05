#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

int n, s;

void solve() {
    cin >> n >> s;
    int cnt = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int r, c;
        cin >> r >> c;
        if (r == 1)
            cnt++;
        sum += c;
    }
    // cout << "sum:" << sum << endl;
    if (cnt * 2 >= n) {
        cout << 1 << " ";
    } else {
        cout << 0 << " ";   
    }
    if (sum >= s + 50) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}