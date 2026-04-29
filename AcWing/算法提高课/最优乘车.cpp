#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 10;

void solve() {
    int m, n;
    cin >> m >> n;
    cin.ignore();
    vector<int> g[n + 1];
    while (m--) {
        string s;
        getline(cin, s);
        istringstream iss(s);
        vector<int> a;
        int x;
        while (iss >> x)
            a.push_back(x);

        // for (int x : a)
        //     cout << x << ' ';
        // cout << endl;

        for (int i = 0; i < a.size(); i++) {
            for (int j = i + 1; j < a.size(); j++) {
                g[a[i]].push_back(a[j]);
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int x : g[i]) {
    //         cout << x << ' ';
    //     }
    //     cout << endl;
    // }

    queue<int> q;
    vector<int> d(n + 1, 0x3f3f3f3f);
    q.push(1);
    int res = -1;
    d[1] = 0;
    while (q.size()) {
        auto x = q.front();
        q.pop();
        // cout << x << ' ' << d[x] << endl;
        if (x == n) {
            res = d[n];
            break;
        }
        // if (d[x] != 0x3f3f3f3f)
        //     continue;
        for (auto y : g[x]) {
            if (d[y] > d[x] + 1) {
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }
    if (res == -1)
        cout << "NO" << endl;
    else
        cout << (res - 1 > 0 ? res - 1 : 0) << endl;
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
