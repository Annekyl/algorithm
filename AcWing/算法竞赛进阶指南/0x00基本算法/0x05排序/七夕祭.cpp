#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e5 + 10;

int n, m, t;
int x[N], y[N];
int r[N], c[N];
int s[N]; // 前缀和

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> t;
    for (int i = 1; i <= t; i++) {
        cin >> x[i] >> y[i];
    }

    if (t % m == 0 && t % n == 0) {
        cout << "both" << " ";
    } else if (t % n == 0) {
        cout << "row" << " ";
    } else if (t % m == 0) {
        cout << "column" << " ";
    } else {
        cout << "impossible" << endl;
        return 0;
    }

    ll ans = 0;
    if (t % n == 0) {
        // 统计每行的数量
        for (int i = 1; i <= t; i++) {
            r[x[i]]++;
        }

        int sub = t / n;
        memset(s, 0, sizeof s);
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + r[i] - sub;
        }

        sort(s + 1, s + n + 1);
        int mid = s[(n + 1) / 2];
        for (int i = 1; i <= n; i++) {
            ans += abs(s[i] - mid);
        }
    }

    if (t % m == 0) {
        // 统计每列的数量
        for (int i = 1; i <= t; i++) {
            c[y[i]]++;
        }

        int sub = t / m;
        memset(s, 0, sizeof s);
        for (int i = 1; i <= m; i++) {
            s[i] = s[i - 1] + c[i] - sub;
        }

        sort(s + 1, s + m + 1);
        int mid = s[(m + 1) / 2];
        for (int i = 1; i <= m; i++) {
            ans += abs(s[i] - mid);
        }
    }
    cout << ans;
    return 0;
}