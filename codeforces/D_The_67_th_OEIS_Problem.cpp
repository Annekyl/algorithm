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
const int N = 6e6 + 10;

int prime[N], cnt;
int a[N];

void get_prime(int n) {
    bool v[n];
    for (int i = 2; i < n; i++) {
        if (!v[i])
            prime[cnt++] = i;
        for (int j = 0; i * prime[j] < n; j++) {
            v[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    get_prime(1e6);
    for (int i = 0; i < 10000; i++) {
        a[i] = prime[i] * prime[i + 1];
    }
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
