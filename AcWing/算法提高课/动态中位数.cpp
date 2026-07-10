#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)
#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
const int N = 1e5 + 10;

void solve() {
    int p;
    cin >> p;
    for (int _ = 1; _ <= p; _++) {
        int id, m;
        cin >> id >> m;
        cout << id << " " << (m + 1) / 2 << endl;
        priority_queue<int> down;                          // 小于等于中位数
        priority_queue<int, vector<int>, greater<int>> up; // 大于中位数
        int a[m];
        vi ans;
        for (int i = 0; i < m; i++) {
            cin >> a[i];
            if (down.empty())
                down.push(a[i]);
            else {
                int t = down.top();
                if (a[i] <= t)
                    down.push(a[i]);
                else
                    up.push(a[i]);

                if (down.size() > up.size() + 1) {
                    int t = down.top();
                    down.pop();
                    up.push(t);
                } else if (down.size() < up.size()) {
                    int t = up.top();
                    up.pop();
                    down.push(t);
                }
            }

            if (i % 2 == 0) {
                // cout << i << " ";
                ans.push_back(down.top());
            }
        }
        // cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            if (i != 0 && i % 10 == 0)
                cout << endl;
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
