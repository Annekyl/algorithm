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

int n, m;

void solve() {
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int x = 0, y = 1;
    int day = 0;
    for (int i = 0; i < n; i++) {
        bool buy = false;
        if (x >= a[i]) {
            int val = m - day;
            if (a[i] < val) {
                x -= a[i];
                y++;
                buy = true;
            }
        } else {
            int need = (a[i] - x + y - 1) / y;
            // 剩余天数不够
            if (day + need > m)
                break;
            int val = m - day - need;
            if (val > a[i]) {
                x += need * y - a[i];
                y++;
                day += need;
                buy = true;
            }
        }
        if (!buy)
            break;
    }
    x += (m - day) * y;

    cout << x << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}