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
constexpr int N = 5010;

int a, b;
int primes[N], tot;
int power[N];
int v[N];

void get_primes() {
    FOR(i, 2, N - 1) {
        if (!v[i]) {
            primes[++tot] = i;
        }
        for (int j = 1; primes[j] <= N / i; j++) {
            v[primes[j] * i] = 1;
            if (i % primes[j] == 0)
                break;
        }
    }
}

int get_power(int n, int p) {
    int res = 0;
    while (n) {
        res += n / p;
        n /= p;
    }
    return res;
}

vi mul(vi a, int b) {
    vi ans;
    int t = 0; // 进位
    for (auto &x : a) {
        t += x * b;
        ans.push_back(t % 10);
        t /= 10;
    }
    while (t) {
        ans.push_back(t % 10);
        t /= 10;
    }
    return ans;
}

void solve() {
    cin >> a >> b;
    get_primes();

    FOR(i, 1, tot) {
        int p = primes[i];
        power[i] = get_power(a, p) - get_power(b, p) - get_power(a - b, p);
    }

    vi ans;
    ans.push_back(1);
    for (int i = 1; i <= tot; i++) {
        for (int j = 1; j <= power[i]; j++) {
            ans = mul(ans, primes[i]);
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
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