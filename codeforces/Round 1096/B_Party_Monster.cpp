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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int N = 1e5 + 10;

int n;

void solve() {
    cin >> n;
    string s;
    cin >> s;
    if (n & 1) {
        cout << "NO" << endl;
        return;
    }
    int left = 0, right = 0;
    for (char c : s) {
        if (c == '(')
            left++;
        else
            right++;
    }
    if (left != right) {
        cout << "NO" << endl;
        return;
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
