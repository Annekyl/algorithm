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
constexpr int N = 1e6 + 10;

int n;
int prime[N], m;
int v[N];
int ans;

void solve() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (v[i])
            continue;
        prime[++m] = i;
        for (int j = i; j <= n / i; j++) {
            v[i * j] = 1;
        }
    }
    cout << m;
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