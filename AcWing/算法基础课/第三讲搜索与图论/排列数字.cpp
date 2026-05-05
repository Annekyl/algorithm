#include "bits/stdc++.h"

#define int long long
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 10;

int n;
vector<int> ans;
bool v[N];

void dfs() {
    if (ans.size() == n) {
        for (auto &num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }

    FOR(i, 1, n) {
        if (!v[i]) {
            ans.push_back(i);
            v[i] = 1;
            dfs();
            ans.pop_back();
            v[i] = 0;
        }
    }
}

void solve() {
    memset(v, 0, sizeof v);
    cin >> n;
    dfs();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}