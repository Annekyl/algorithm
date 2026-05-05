#include "bits/stdc++.h"

#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

struct Point {
    int x, y;
};

int n;
Point a[N]; // 核电站坐标
Point b[N]; // 特工坐标

void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i].x >> a[i].y;
    FOR(i, 1, n) cin >> b[i].x >> b[i].y;
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