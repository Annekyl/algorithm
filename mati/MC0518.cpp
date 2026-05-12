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
    int n;
    cin >> n;
    map<int, string> mp;
    for (int i = 0; i < n; i++) {
        int p;
        string s;
        cin >> p >> s;
        mp.insert({p, s});
    }
    string s, ans;
    cin.ignore();
    getline(cin, s);
    int pos = 0;
    while (pos < s.size()) {
        char c = s[pos];
        if (c != '#') {
            ans += c;
        } else {
            int id = 0;
            while (s[pos + 1] >= '0' && s[pos + 1] <= '9') {
                pos++;
                id = id * 10 + (s[pos] - '0');
            }
            ans += mp[id];
        }
        pos++;
    }
    cout << ans << endl;
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