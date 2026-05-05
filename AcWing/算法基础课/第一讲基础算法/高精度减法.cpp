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

vi a, b, c;

bool cmp(vi a, vi b) {
    if (a.size() != b.size())
        return a.size() > b.size();
    FOR(i, 0, a.size() - 1) {
        if (a[i] != b[i]) {
            return a[i] > b[i];
        }
    }
    return true;
}

void sub(vi a, vi b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0, t = 0, k = 0; i < a.size(); i++) {
        t += a[i] - k;
        if (i < b.size())
            t -= b[i];

        if (t < 0) {
            k = 1;
            t += 10;
        } else {
            k = 0;
        }

        c.push_back(t % 10);
        t /= 10;
    }

    // 去除前导零
    while (c.back() == 0 && c.size() > 1)
        c.pop_back();

    reverse(c.begin(), c.end());
}

void solve() {
    string s;
    cin >> s;
    FOR(i, 0, s.size() - 1) a.push_back(s[i] - '0');
    cin >> s;
    FOR(i, 0, s.size() - 1) b.push_back(s[i] - '0');
    if (cmp(a, b)) {
        sub(a, b);
    } else {
        sub(b, a);
        c[0] *= -1;
    }
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