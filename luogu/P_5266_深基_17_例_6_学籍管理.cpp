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
    int q;
    cin >> q;
    map<string, int> mp;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            string name;
            int sc;
            cin >> name >> sc;
            mp[name] = sc;
            cout << "OK" << endl;
        } else if (op == 2) {
            string name;
            cin >> name;
            auto it = mp.find(name);
            if (it == mp.end()) {
                cout << "Not found" << endl;
            } else {
                cout << (*it).second << endl;
            }
        } else if (op == 3) {
            string name;
            cin >> name;
            auto it = mp.find(name);
            if (it == mp.end()) {
                cout << "Not found" << endl;
            } else {
                mp.erase(it);
                cout << "Deleted successfully" << endl;
            }
        } else {
            cout << mp.size() << endl;
        }
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
