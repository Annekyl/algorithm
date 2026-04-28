#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 50;

int w, n;
vector<int> a;
vector<int> s;
int k;
int ans = 0;

void dfs1(int x, int idx) {
    // cout << x << ' ' << idx << endl;
    // cout << k << endl;
    // debug(k);
    if (idx >= k) {
        s.push_back(x);
        return;
    }

    dfs1(x, idx + 1);
    if (x + a[idx] <= w) {
        dfs1(x + a[idx], idx + 1);
    }
}

void dfs2(int sum, int idx) {
    if (idx >= n) {
        // 需要在s中找小于等于w - sum中最大的数
        int l = 0, r = s.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (s[mid] + sum <= w) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (s[l] + sum <= w)
            ans = max(ans, s[l] + sum);
        return;
    }

    dfs2(sum, idx + 1);
    if (sum + a[idx] <= w)
        dfs2(sum + a[idx], idx + 1);
}

void solve() {
    cin >> w >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    // for (int x : a)
    //     cout << x << ' ';
    // cout << endl;

    k = n / 2;

    // debug(k);
    // for (int x : s)
    //     cout << x << ' ';
    // cout << endl;

    dfs1(0, 0);

    // for (int x : s)
    //     cout << x << ' ';
    // cout << endl;

    sort(s.begin(),s.end());
    s.erase(unique(s.begin(), s.end()), s.end());

    // for (int x : s)
    //     cout << x << ' ';
    // cout << endl;

    dfs2(0, k);
    // cout << 1 << endl;
    // exit(0);
    cout << ans << endl;
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
