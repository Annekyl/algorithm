#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 50;

int w, n;
vector<int> a(N);
vector<int> s;
int k;

void dfs1(int x, int idx) {
    if (idx >= k) {
        s.push_back(x);
        return;
    }

    dfs1(x, idx + 1);
    if (x + a[idx] <= w) {
        dfs1(x + a[idx], idx + 1);
    }
}

void dfs2(){

}

void solve() {
    cin >> w >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int k = n / 2;
    dfs1(0, 0);

    s.erase(unique(s.begin(), s.end()), s.end());

	dfs2(0,0);
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
