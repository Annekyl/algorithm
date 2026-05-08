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
const int N = 1e5 + 10;

void solve() {
    int n;
    cin >> n;
    int cnt[7] = {0};
    int rating = 1000;
    while (n--) {
        int x;
        cin >> x;
        rating += x;
        if (rating < 700) {
            cnt[0]++;
        } else if (rating < 1100) {
            cnt[1]++;
        } else if (rating < 1500) {
            cnt[2]++;
        } else if (rating < 2000) {
            cnt[3]++;
        } else if (rating < 2400) {
            cnt[4]++;
        } else if (rating < 2800) {
            cnt[5]++;
        } else {
            cnt[6]++;
        }
    }
    for (int i = 0; i < 7; i++)
        cout << cnt[i] << " ";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
