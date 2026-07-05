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
    string a, b;
    cin >> a >> b;
    int i = 0, j = 0;
    while (a[i] != '.')
        i++;
    int cnt1 = a.size() - i - 1; // 小数点后面有几位
    while (b[j] != '.')
        j++;
    int cnt2 = b.size() - j - 1;
    if (cnt1 > cnt2) {
        int add = cnt1 - cnt2;
        while (add) {
            b.push_back('0');
            add--;
        }
    } else {
        int add = cnt2 - cnt1;
        while (add) {
            a.push_back('0');
            add--;
        }
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    i = 0, j = 0;
    int ans = 0;
    int sum = 0;
    // cout << a << ' ' << b << endl;
    while (i < a.size() || j < b.size()) {
        if (i < a.size()) {
            sum += a[i] - '0';
            i++;
            if (a[i] == '.')
                i++;
        }
        if (j < b.size()) {
            sum += b[j] - '0';
            j++;
            if (b[j] == '.')
                j++;
        }
        // cout << sum << endl;
        if (sum >= 10) {
            // cout << i << ' ' << j << endl;
            ans++;
        }
		sum /= 10;
    }
    cout << ans << endl;
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
