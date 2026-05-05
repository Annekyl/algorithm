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

int qmi(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int c(int a, int b, int p) {
    int res = 1;
    for (int i = 1, j = a; i <= b; i++, j--) {
        res = res * j % p;
        res = res * qmi(i, p - 2, p) % p;
    }
    return res;
}

int lucas(int a, int b, int p) {
    if (a < p && b < p)
        return c(a, b, p);
    int res = c(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
    return res;
}

void solve() {
    cin >> n;
    while (n--) {
        int a, b, p;
        cin >> a >> b >> p;
        cout << lucas(a, b, p) << endl;
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