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
int a1, a2, m1, m2;
int x;

int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

void solve() {
    cin >> n;
    cin >> m1 >> a1;
    bool flag = 1;
    FOR(i, 2, n) {
        cin >> m2 >> a2;
        int k1, k2;
        int d = exgcd(m1, m2, k1, k2);
        if ((a2 - a1) % d) {
            flag = 0;
            break;
        }

        k1 *= (a2 - a1) / d;
        int t = m2 / d;
        k1 = (k1 % t + t) % t;

        x = k1 * m1 + a1;
        int m = m1 / d * m2;
        a1 = k1 * m1 + a1;
        m1 = m;
    }
    if (!flag)
        cout << -1 << endl;
    else {
        x = (a1 % m1 + m1) % m1;
        cout << x << endl;
    }
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