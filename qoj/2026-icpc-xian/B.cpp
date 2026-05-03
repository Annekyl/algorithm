#include "bits/stdc++.h"

#define int long long
#define endl '\n'
#define debug(x) cout << #x << " " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

int n, x, y;

void solve() {
    cin >> n >> x >> y;
    string s;
    cin >> s;
    vi s0(n + 1), s1(n + 1), s2(n + 1);
    for (int i = 1; i <= n; i++) {
        s0[i] = s0[i - 1] + (s[i - 1] == '0');
        s1[i] = s1[i - 1] + (s[i - 1] == '1');
        s2[i] = s2[i - 1] + (s[i - 1] == '2');
    }

    int cycle = (x + y) / n;
    int pos = (x + y) % n;

    int need0 = x - cycle * s0[n] - s0[pos];
    if (need0 < 0) {
        cout << -1 << endl;
        return;
    }

    int pre_mx = s2[pos];
    int suf_mx = s2[n] - s2[pos];

    int pre0 = -1, suf0 = -1;
    if (cycle == 0) {
        // 需要的0全部由前缀提供
        if (pre_mx >= need0) {
            pre0 = need0;
            suf0 = suf_mx;
        }
    } else {
        for (int i = pre_mx; i >= 0; i--) {       // 枚举前缀中0的个数
            int remain = need0 - i * (cycle + 1); // 后缀需要提供的0的个数
            if (remain >= 0 && remain % cycle == 0 &&
                remain / cycle <= suf_mx) {
                pre0 = i;
                suf0 = remain / cycle;
                break;
            }
        }
    }

    if (pre0 == -1) {
        cout << -1 << endl;
        return;
    }

    string ans="";
    for (int i = 0; i < n; i++) {
        if (s[i] != '2')
            ans += s[i];
        else {
            if (i < pos) {
                if (pre0) {
                    ans += '0';
                    pre0--;
                } else {
                    ans += '1';
                }
            } else {
                if (suf0) {
                    ans += '0';
                    suf0--;
                } else {
                    ans += '1';
                }
            }
        }
    }
    cout << ans << endl;
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