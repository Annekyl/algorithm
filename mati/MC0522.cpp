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

void solve() {
    map<char, int> mp;
    string s;
    cin >> s;
    for (char c : s)
        mp[c]++;
    int up = min({mp['M'], mp['T'], mp['J'], mp['A'], mp['I'] / 2});
    int down = min({mp['m'], mp['t'], mp['j'], mp['a'], mp['i'] / 2});
    // int ans = up + down;
    // cout << ans << endl;
    cout << up << ' ' << down << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}