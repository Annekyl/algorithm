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

int n;

void solve() {
    // cin >> n;
    string s;
    cin >> s;
    if (s.size() < 12) {
        cout << "NO" << endl;
        return;
    }
    if (s.substr(0, 9) != "ucup-team") {
        cout << "NO" << endl;
        return;
    }
    if (s[9] == '0') {
        cout << "NO" << endl;
        return;
    }
    for (int i = 9; i < s.size(); i++) {
        if (s[i] < '0' || s[i] > '9') {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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