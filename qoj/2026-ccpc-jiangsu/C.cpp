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
    string s;
    cin >> s;
    int ans = s[0] - '0';
    for (int i = 1; i < n - 1; i++) {
        ans = ans & (s[i] - '0');
    }
    if (ans == 1 && s[n - 1] == '1') {
        for (int i = 0; i < n - 2; i++)
            cout << "&";
        cout << '^' << endl;
    } else if (ans == 1 && s[n - 1] == '0') {
        for (int i = 0; i < n - 2; i++)
            cout << "&";
        cout << '&' << endl;
    } else if (ans == 0 && s[n - 1] == '1') {
        for (int i = 0; i < n - 2; i++)
            cout << "&";
        cout << '&' << endl;
    } else {
        for (int i = 0; i < n - 2; i++)
            cout << "&";
        cout << '&' << endl;
    }
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