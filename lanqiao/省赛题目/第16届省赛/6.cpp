#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e5 + 10;

int n;
vi a(N, 0);
string g[2];

void solve() {
    // cin >> n;
    cin >> g[0];
    cin >> g[1];
    int mx = -1, mn = -1;
    for (int i = 0; i < g[i].size(); i++) {
        for (int j = 0; j < 2; j++) {
            if (g[j][i] == '#') {
                if (mn == -1)
                    mn = i;
                mx = i;
            }
        }
    }

    int ans = 0;
    pii point;
    for (int i = mn; i <= mx; i++) {
        if (g[i][0] == '#' && g[i][1] == '#') {

        } else if (g[i][0] == '#' && g[i][1] == '.') {

        } else if (g[i][0] == '.' && g[i][1] == '#') {

        } else {
            ans++;
        }
    }
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}