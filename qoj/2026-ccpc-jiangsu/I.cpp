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
    string s, t;
    cin >> s >> t;

    auto check = [](string s, char a, char b) -> bool {
        int suc = false;
        char c = a;
        for (char ss : s) {
            if (!suc && ss == c) {
                suc = true;
                c = b;
            } else if (suc && ss == c) {
                return true;
            }
        }
        return false;
    };

    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = 'a'; b <= 'z'; b++) {
            if (check(s, a, b) && check(t, a, b)) {
                cout << a << b << endl;
                return;
            }
        }
    }
    cout << "HENG!" << endl;
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