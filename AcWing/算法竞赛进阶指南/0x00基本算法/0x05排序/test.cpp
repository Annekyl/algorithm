#include "bits/stdc++.h"

#define int long long

using namespace std;

const int N = 1e5 + 10;

int n, m, t;
int x[N], y[N];
int a[N];
int s[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> t;
    for (int i = 1; i <= t; i++) {
        cin >> x[i] >> y[i];
    }

    int row = t % n, column = t % m;
    if (row == 0 && column == 0) {
        cout << "both ";
    } else if (row == 0) {
        cout << "row ";
    } else if (column == 0) {
        cout << "column ";
    } else {
        cout << "impossible";
        return 0;
    }

    int ans = 0;
    if (row == 0) {
        memset(a, 0, sizeof a);
        for (int i = 1; i <= t; i++) {
            a[x[i]]++;
        }
        int num = t / n;
        for (int i = 1; i <= n; i++) {
            a[i] -= num;
        }

        memset(s, 0, sizeof s);
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + a[i];
        }
        sort(s + 1, s + n + 1);
        int sub = s[(1 + n) / 2];
        for (int i = 1; i <= n; i++) {
            ans += abs(s[i] - sub);
        }
    }

    if (column == 0) {
        memset(a, 0, sizeof a);
        for (int i = 1; i <= t; i++) {
            a[y[i]]++;
        }
        int num = t / m;
        for (int i = 1; i <= m; i++) {
            a[i] -= num;
        }

        memset(s, 0, sizeof s);
        for (int i = 1; i <= m; i++) {
            s[i] = s[i - 1] + a[i];
        }
        sort(s + 1, s + m + 1);
        int sub = s[(m + 1) / 2];
        for (int i = 1; i <= m; i++) {
            ans += abs(s[i] - sub);
        }
    }

    cout << ans;
}