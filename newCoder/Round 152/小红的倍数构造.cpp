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
typedef unsigned long long ull;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
const int N = 1e5 + 10;

bool st[10];

bool valid(int x) {
    while (x) {
        if (!st[x % 10])
            return false;
        x /= 10;
    }
    return true;
}

void solve() {
    // int x;
    // cin >> x;
    // int temp = x;
    // while (temp) {
    //     st[temp % 10] = true;
    //     temp /= 10;
    // }
    // int i = 2;
    // while (1) {
    //     if (valid(x * i)) {
    //         // cout << i << endl;
    //         cout << x * i << endl;
    //         return;
    //     }
    //     i++;
    // }
    string s;
    cin >> s;
    cout << s << s << endl;
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
