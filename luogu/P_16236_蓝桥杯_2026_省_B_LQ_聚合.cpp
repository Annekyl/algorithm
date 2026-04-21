#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define DEBUG

#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << '\n'
#else
#define debug(x)
#endif

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;

int n;

void solve() {
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;

    int suffix[n + 2]; // 后缀Q的总数
    memset(suffix, 0, sizeof suffix);
    for (int i = n; i > 0; i--) {
        suffix[i] = suffix[i + 1] + (s[i] != 'L');
    }
    // for (int i = 1; i <= n; i++)
    //     debug(suffix[i]);

    int ans = 0;
    int cnt_l = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'L')
            cnt_l++;
        else
            ans += cnt_l;
    }
    // debug(ans);

    cnt_l = 0;
    int sum = ans;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'L')
            cnt_l++;
        else if (s[i] == '?') {
            sum += suffix[i + 1] - cnt_l;
            cnt_l++;
        }

        ans = max(ans, sum);
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
