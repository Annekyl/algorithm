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
constexpr int N = 110;

int n;
int a[N];
int p[N], c[N];

void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) {
        int x = a[i];
        // cout << x << endl;

        // 分解质因数
        int cnt = 0; // 质因数的个数
        for (int j = 2; j <= x / j; j++) {
            if (x % j == 0) {
                p[++cnt] = j, c[cnt] = 0;
                while (x % j == 0) {
                    x /= j, c[cnt]++;
                }
            }
        }
        if (x != 1) {
            p[++cnt] = x;
            c[cnt] = 1;
        }

        FOR(j, 1, cnt) { cout << p[j] << " " << c[j] << endl; }
        cout << endl;
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