#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e4 + 10;

int n, m, k, s;

void solve() {
    int a[N];         // 存储每个商店放的商品类别
    vector<int> g[N]; // 邻接表

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int d[n + 1][k + 1];
    memset(d, 0x3f, sizeof d);
    // i:商品
    for (int i = 1; i <= k; i++) {
        queue<int> q;
        // j：商店
        for (int j = 1; j <= n; j++) {
            if (a[j] == i) {
                d[j][i] = 0;
                q.push(j);
            }
        }
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (auto y : g[x]) {
                if (d[y][i] > d[x][i] + 1) {
                    d[y][i] = d[x][i] + 1;
                    q.push(y);
                }
            }
        }
    }

    // i:商店
    for (int i = 1; i <= n; i++) {
        vector<int> dis;
        // J:商品
        for (int j = 1; j <= k; j++) {
            if (j != a[i]) {
                dis.push_back(d[i][j]);
            }
        }
        sort(dis.begin(), dis.end());
        int sum = 0;
        for (int j = 0; j < s - 1; j++) {
            sum += dis[j];
        }
        cout << sum << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> m >> k >> s) {
        solve();
    }

    return 0;
}