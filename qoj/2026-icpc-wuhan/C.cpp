#include "bits/stdc++.h"

#define int long long
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

void solve() {
    int n;
    cin >> n;
    int s, d, hp;
    cin >> s >> d >> hp;
    for (int i = 1; i <= n; i++) {
        int a, k;
        cin >> a >> k;
        int fangyu = (k + d - 1) / d;
        // 最多选三张牌
        int mx_daji = min(a, 3LL);
        // 可以直接打死
        if (mx_daji * s >= hp) {
            cout << "Yes" << endl;
            cout << i << endl;
            return;
        } else {
            if (fangyu > 5 - a || fangyu > 3) {
                cout << "No" << endl;
                return;
            }
            int daji = min(3 - fangyu, a);
            hp -= s * daji;
        }
    }
    cout << "No" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}