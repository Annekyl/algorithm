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

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    set<int> x_cut, y_cut;
    x_cut.insert(0);
    x_cut.insert(n);
    y_cut.insert(0);
    y_cut.insert(m);

    multiset<int> x_lens, y_lens;
    x_lens.insert(n);
    y_lens.insert(m);
    while (q--) {
        int op, k;
        cin >> op >> k;
        if (op == 1) {
            // 切割x轴
            x_cut.insert(k);
            auto it = x_cut.find(k);
            int pre = *(prev(it));
            int ne = *(next(it));
            x_lens.erase(x_lens.find(ne - pre));
            x_lens.insert(k - pre);
            x_lens.insert(ne - k);
        } else {
            // 切割y轴
            y_cut.insert(k);
            auto it = y_cut.find(k);
            int pre = *(prev(it));
            int ne = *(next(it));
            y_lens.erase(y_lens.find(ne - pre));
            y_lens.insert(k - pre);
            y_lens.insert(ne - k);
        }
        int mx = (*x_lens.rbegin()) * (*y_lens.rbegin());
        cout << mx << endl;
    }
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