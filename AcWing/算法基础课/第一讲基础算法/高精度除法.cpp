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

vi a, c;
int b;

int div(vi a, int b) {
    int t = 0;
    for (int i = 0; i < a.size(); i++) {
        t = t * 10 + a[i];
        c.push_back(t / b);
        t %= b;
    }
    reverse(c.begin(), c.end());
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();
    reverse(c.begin(), c.end());
    return t;
}

void solve() {
    string s;
    cin >> s >> b;
    FOR(i, 0, s.size() - 1) a.push_back(s[i] - '0');
    int t = div(a, b);
    FOR(i, 0, c.size() - 1) cout << c[i];
    cout << endl << t;
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