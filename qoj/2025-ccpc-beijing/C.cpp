#include "bits/stdc++.h"

#define int long long
#define endl '\n'
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

int n, m;
int s[40], a[40];
void init() {
    a[1] = 1;
    s[1] = 1;
    for (int i = 2; i < 40; i++) {
        a[i] = s[i - 1] + 1;
        s[i] = s[i - 1] + a[i];
    }
}

bool check(int mid) {
    int mx = mid * (mid - 1) / 2 + (m - mid + 1) * mid;
    return n <= mid;
}

void solve() {
    cin >> n >> m;
    if (m >= n) {
        cout << 1 << endl;
        return;
    }
    int mx = (m < 40 ? s[m] : s[35]);
    if (n > mx) {
        cout << -1 << endl;
        return;
    }
    int ans = -1;
    for (int i = 1; i < 40; i++) {
        // if (i > m)
        //     break;
        int need = (n - s[i] + m - i - 1) / (m - i);
        // cout << i << ' ' << need << endl;
        if (need <= a[i + 1]) {
            ans = max(need, a[i]);
            break;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    // for (int i = 1; i < 32; i++) {
    //     cout << a[i] << ' ' << s[i] << endl;
    // }
    // cout << "----------" << endl;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}