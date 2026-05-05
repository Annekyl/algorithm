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
vi a, b, c;

void add(vi a, vi b) {
    int t = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0, t = 0; i < a.size() || i < b.size() || t; i++) {
        if (i < a.size())
            t += a[i];
        if (i < b.size())
            t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    reverse(c.begin(), c.end());
}

void solve() {
    string s;
    cin >> s;
    FOR(i, 0, s.size() - 1) a.push_back(s[i] - '0');
    cin >> s;
    FOR(i, 0, s.size() - 1) b.push_back(s[i] - '0');
    add(a, b);
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