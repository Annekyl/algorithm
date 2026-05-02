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
    cin >> n;
    int cnt = n / 97, remain = n % 97;
    // cout << cnt << ' ' << remain << endl;
    if (remain > cnt * 25) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    int zcnt = remain / 25, other = remain % 25;
    for (int i = 0; i < cnt; i++) {
        if (i < zcnt)
            cout << 'z';
        else if (i == zcnt)
            cout << (char)('a' + other);
        else
            cout << "a";
    }
    cout << endl;
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