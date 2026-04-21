#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef vector<int> vi;

const int N = 1e5 + 10;

int n;
vi a(N, 0);

void solve() {
    // cin >> n;
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    while (k--) {
        int temp_a = a, temp_b = b;
        a = (b + c) / 2;
        b = (temp_a + c) / 2;
        c = (temp_a + temp_b) / 2;
    }
    cout << a << " " << b << " " << c << endl;
}

signed main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}