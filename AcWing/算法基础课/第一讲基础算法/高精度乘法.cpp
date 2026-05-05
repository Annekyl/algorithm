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
constexpr int N = 1e5 + 10;

int n;
vi a, c;
int b;

void mul(vi a, int b) {
    reverse(a.begin(), a.end());
    for (int i = 0, t = 0; i < a.size() || t; i++) {
        if (i < a.size())
            t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    reverse(c.begin(), c.end());
}

void solve() {
    string s;
    cin >> s;
    FOR(i, 0, s.size() - 1) a.push_back(s[i] - '0');
    cin >> b;
    if (b == 0) {
        cout << 0;
        return;
    }
    mul(a, b);
    FOR(i, 0, c.size() - 1) cout << c[i];
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