#include "bits/stdc++.h"
#define int long long
#define debug(x) cout << #x << " " << x << endl
using namespace std;

typedef pair<int, int> pii;

struct Point {
    int x, y, z;
    bool operator<(const struct Point &b) const {
        if (z != b.z)
            return z < b.z;
        else if (x != b.x)
            return x < b.x;
        return y < b.y;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    int sx, sy, sz, tx, ty, tz;
    cin >> sx >> sy >> sz >> tx >> ty >> tz;
    Point a[n];
    map<pii, vector<int>> mp;
    map<Point, int> find_idx;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = {x, y, z + 1};
    }
    sort(a, a + n);
    // for (auto [x, y, z] : a) {
    //     cout << x << ' ' << y << ' ' << z << endl;
    // }
    // cout << endl;
    for (int i = 0; i < n; i++) {
        auto [x, y, z] = a[i];
        mp[{x, y}].push_back(z);
        // find_idx[{x, y, z}] = i;
        find_idx.insert({Point{x, y, z}, i});
        // cout << x << ' ';
        // cout << y << ' ';
        // cout << z << ' ';
        // cout << find_idx[{x, y, z}] << " ";
        // cout << i << endl;
    }
    // cout << endl;
    // for (auto [temp, z] : mp) {
    //     cout << temp.first << ' ' << temp.second << ':';
    //     for (auto temp : z) {
    //         cout << temp << ' ';
    //     }
    //     cout << endl;
    // }
    // for (auto [point, idx] : find_idx) {
    //     cout << point.x << ' ';
    //     cout << point.y << ' ';
    //     cout << point.z << ':';
    //     cout << idx << endl;
    // }
    // cout << find_idx[{3, 3, 3}] << endl;
    // cout << find_idx[{2, 3, 3}] << endl;

    Point d[m];
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        d[i] = {x, y, z};
    }
    vector<int> g[n];

    for (int i = 0; i < n; i++) {
        auto [x, y, z] = a[i];
        for (int j = 0; j < m; j++) {
            int nx = x + d[j].x;
            int ny = y + d[j].y;
            int nz = z + d[j].z;
            if (find_idx.find({nx, ny, nz + 1}) != find_idx.end()) {
                continue;
            }
            if (mp.find({nx, ny}) == mp.end())
                continue;
            auto arrive = mp[{nx, ny}];
            // 最小值都大于nz，就不能连接这条边
            if (arrive[0] > nz)
                continue;
            // 二分找小于等于nz的最大值
            int l = 0, r = arrive.size() - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (arrive[mid] <= nz) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }

            g[i].push_back(find_idx[{nx, ny, arrive[l]}]);
        }
    }
    // exit(0);
    // for (int i = 0; i < n; i++) {
    //     cout << a[i].x << ' ' << a[i].y << ' ' << a[i].z << "-----";
    //     cout << i << ":";
    //     for (int y : g[i]) {
    //         cout << y << ' ';
    //     }
    //     cout << endl;
    // }

    int dist[n];
    vector<int> v(n, false);
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    int st = find_idx[{sx, sy, sz}], ed = find_idx[{tx, ty, tz}];
    dist[st] = 0;
    // debug(st);
    // debug(ed);
    q.push({0, st});
    while (q.size()) {
        auto [step, x] = q.top();
        q.pop();
        if (v[x])
            continue;
        v[x] = true;
        if (x == ed)
            break;

        for (int y : g[x]) {
            if (dist[y] > dist[x] + 1) {
                dist[y] = dist[x] + 1;
                q.push({dist[y], y});
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << dist[i] << endl;
    // }

    if (dist[ed] == 0x3f3f3f3f3f3f3f3f)
        cout << -1 << endl;
    else
        cout << dist[ed] << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}