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

vi get_divisors(int x) {
    vi res;
    for (int i = 1; i <= x / i; i++) {
        if (x % i == 0) {
            res.push_back(i);
            if (x / i != i)
                res.push_back(x / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) {
        auto nums = get_divisors(a[i]);
        for (auto x : nums) {
            cout << x << " ";
        }
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