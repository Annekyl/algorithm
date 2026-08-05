#include "bits/stdc++.h"

#define int long long
#define endl '\n'
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

struct Node {
    int t, pos, neg;
};

void solve() {
    int n, d;
    cin >> n >> d;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    vector<Node> node;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (node.empty() || node.back().t != a[i]) {
            node.push_back({a[i], 0, 0});
        }
        auto &t = node.back();
        if (c == '+')
            t.pos++;
        else
            t.neg++;
    }
    int ans = 0;
    int s1 = 0, s2 = 0;
    for (int l = 0, r = 0; r < node.size(); r++) {
        while (l < r && node[r].t - node[l].t > d) {
            s1 -= node[l].pos;
            s2 -= node[l].neg;
            l++;
        }
        ans += node[r].pos * s2;
        ans += node[r].neg * s1;

        s1 += node[r].pos;
        s2 += node[r].neg;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}