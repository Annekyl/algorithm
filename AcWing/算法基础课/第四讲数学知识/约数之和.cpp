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
constexpr int mod = 1e9 + 7;
constexpr int N = 1e5 + 10;

int n;
unordered_map<int, int> mp;

void primes(int num) {
    FOR(i, 2, num / i) {
        while (num % i == 0) {
            mp[i]++;
            num /= i;
        }
    }
    if (num > 1) {
        mp[num]++;
    }
}

void solve() {
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        primes(x);
    }

    int ans = 1;
    for (auto &[p, c] : mp) {
        int mul = 1;
        int add = p;
        FOR(i, 1, c) {
            mul = (mul + add) % mod;
            add = (add * p) % mod;
        }
        ans = (ans * mul) % mod;
    }
    cout << ans;
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