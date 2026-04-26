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
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= 90)
            d++;
        else if (x >= 80)
            c++;
        else if (x >= 60)
            b++;
        else
            a++;
    }
    cout << a << ' ' << b << ' ' << c << " " << d << endl;
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