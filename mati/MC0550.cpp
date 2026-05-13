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
    int n, q;
    cin >> n >> q;
    vi cnt(2010, 0);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        sum += x;
    }
    while (q--) {
        int x;
        cin >> x;
        if (x == 1 || sum == 0) {
            cout << sum << endl;
        } else {
            vi temp(2010, 0);
            int temp_sum = 0;
            for (int i = 0; i <= 2000; i++) {
                if (cnt[i]) {
                    temp[i / x] += cnt[i];
                }
            }
            for (int i = 0; i <= 2000; i++) {
                temp_sum += temp[i] * i;
            }
            cnt = temp;
            sum = temp_sum;
            cout << sum << endl;
        }
    }
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