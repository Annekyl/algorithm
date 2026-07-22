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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] != s[s.size() - 1]) {
        cout << "empty" << endl;
    } else if (s[0] == '0') {
        int mn = n;
        int len = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                len++;
            } else {
                mn = min(mn, len);
                len = 0;
            }
        }
        mn = min(mn, len);

        if (mn == 0)
            cout << "empty";
        for (int i = 0; i < mn; i++)
            cout << 0;
        cout << endl;
    } else {
        int mn = n;
        int len = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                len++;
            } else {
                mn = min(mn, len);
                len = 0;
            }
        }
        mn = min(mn, len);

        if (mn == 0)
            cout << "empty";
        for (int i = 0; i < mn; i++)
            cout << 1;
        cout << endl;
    }
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