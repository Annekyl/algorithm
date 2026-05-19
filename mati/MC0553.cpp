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

struct Node {
    int val;
    int i, j;
    bool operator<(const Node &other) const {
        if (val != other.val)
            return val > other.val;
        return i != other.i ? i < other.i : j < other.j;
    }
};

void get_k_sz(vi &a, vi &b, vi &res, int k) {
    priority_queue<Node> q;
    int cnt = min(k, (int)a.size());
    for (int i = 0; i < cnt; i++) {
        q.push({a[i] * b[0], i, 0});
    }

    while (k-- && q.size()) {
        auto [val, i, j] = q.top();
        // cout << val << " " << i << " " << j << endl;
        q.pop();
        res.push_back(val);
        if (j + 1 < b.size()) {
            q.push({a[i] * b[j + 1], i, j + 1});
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    vi ab, res;
    get_k_sz(a, b, ab, m);
    sort(ab.begin(), ab.end());

    // for (int x : ab)
    //     cout << x << ' ';
    // cout << endl;

    get_k_sz(ab, c, res, m);
    sort(res.begin(), res.end());
    for (int i = 0; i < m; i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
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