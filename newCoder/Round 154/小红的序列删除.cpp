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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int l = 0, r = 0, u = 0, d = 0;
    for (char c : s) {
        if (c == 'L')
            l++;
        if (c == 'R')
            r++;
        if (c == 'U')
            u++;
        if (c == 'D')
            d++;
    }
    int cnt = 0;
    bool delete_r = false, delete_u = false;
    if (l >= r) {
        delete_r = true;
        cnt += r;
    } else {
        cnt += l;
    }
    if (d >= u) {
        delete_u = true;
        cnt += u;
    } else {
        cnt += d;
    }

    if (cnt >= k) {
        // 删少的两个字母
        for (char c : s) {
            if (k) {
                if (c == 'R' && delete_r) {
                    k--;
                } else if (c == 'U' && delete_u) {
                    k--;
                } else if (c == 'L' && !delete_r) {
                    k--;
                } else if (c == 'D' && !delete_u) {
                    k--;
                } else {
                    cout << c;
                }
            } else {
                cout << c;
            }
        }
        // cout << 1 << endl;
    } else {
        // debug(cnt);
        int cnt2 = k - cnt;
        for (char c : s) {
            if (delete_r) {
                if (c == 'L') {
                    if (cnt2) {
                        cnt2--;
                    } else
                        cout << c;
                }
            } else {
                if (c == 'R') {
                    if (cnt2) {
                        cnt2--;
                    } else
                        cout << c;
                }
            }

            if (delete_u) {
                if (c == 'D') {
                    if (cnt2) {
                        cnt2--;
                    } else
                        cout << c;
                }
            } else {
                if (c == 'U') {
                    if (cnt2) {
                        cnt2--;
                    } else
                        cout << c;
                }
            }
        }
        // cout << 2 << endl;
    }
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
