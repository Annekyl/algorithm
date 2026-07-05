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
    string s, a, b;
    cin >> s;
    reverse(s.begin(), s.end());
    for (int i = 0, add = 0; i < s.size(); i++) {
        int x = s[i] - '0';
        if (i == 0) {
            a += '9';
            int num = x - 9;
            if (num >= 0)
                b += '0' + num;
            else {
                b += '0' + num + 10;
                add = 1;
            }
        } else if (i == 1) {
            b += '9';
            int num = x - 9 - add;
            add = 0;
            if (num >= 0)
                a += '0' + num;
            else {
                a += '0' + num + 10;
                add = 1;
            }
        } else {
            if (x < add) {
                b += s[i] - add + 10;
                add = 1;
            } else {
                b += s[i] - add;
                add = 0;
            }
        }
        // cout << i << ":" << a << ' ' << b << endl;
    }
    while (a.back() == '0')
        a.pop_back();
    while (b.back() == '0')
        b.pop_back();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    cout << a << " " << b << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
