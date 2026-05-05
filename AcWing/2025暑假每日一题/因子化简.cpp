#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e6 + 10;

ll n;
int k;
ll p[N];
int c[N], m;

void divide(ll n) {
    memset(c, 0, sizeof c);
    m = 0;
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            p[++m] = i;
            while (n % i == 0) {
                n /= i;
                c[m]++;
            }
        }
    }
    if (n > 1) {
        p[++m] = n;
        c[m] = 1;
    }
}

ll power(ll base, int exp) {
    ll res = 1;
    for (int i = 0; i < exp; i++) {
        res *= base;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        // cout << "q:" << q << endl;
        cin >> n >> k;
        // cout << n << " " << q << endl;
        divide(n);
        ll ans = 1;
        for (int i = 1; i <= m; i++) {
            // cout << "p c " << p[i] << " " << c[i] << endl;
            if (c[i] >= k) {
                // cout << "p c " << p[i] << " " << c[i] << endl;
                ans *= power(p[i], c[i]);
            }
        }
        cout << ans << endl;
    }

    return 0;
}