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
const int N = 1e6 + 10;

int n;
bool st[N];
int prime[N], cnt;

void precompute() {
    for (int i = 2; i < N; i++) {
        if (!st[i])
            prime[cnt++] = i;
        for (int j = 0; prime[j] * i < N; j++) {
            st[prime[j] * i] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

void solve() {
    // cout << n << endl;
    for (int i = 0; i < cnt; i++) {
        int a = prime[i];
        int b = n - prime[i];
        if (a % 2 == 1 && b % 2 == 1 && !st[b]) {
            cout << n << " = " << a << " + " << b << endl;
            return;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // cout << 1 << endl;
    precompute();
    int t = 1;
    // cin >> t;
    while (cin >> n, n) {
        solve();
    }

    return 0;
}
