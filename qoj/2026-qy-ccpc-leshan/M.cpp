#include "bits/stdc++.h"

using namespace std;

struct node {
    int a, b, c, id;
    bool operator<(const node &other) const { return a < other.a; }
};

void solve() {
    int n;
    cin >> n;
    vector<node> arr(n), now;
    vector<int> idx;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
        arr[i].id = i;
        idx.push_back(i);
    }
    while (idx.size() > 1) {
        now.clear();
        for (int x : idx) {
            now.push_back(arr[x]);
        }
        sort(now.begin(), now.end());

        int sz = idx.size();
        // cout << "idx_sz:" << sz << endl;
        // cout << "before:";
        // for (int x : idx)
        //     cout << x << ' ';
        // cout << endl;
        vector<pair<int, int>> up, down;
        for (int i = 0; i < sz / 2; i++) {
            up.push_back({now[i].b, now[i].id});
        }
        for (int i = sz / 2; i < sz; i++)
            down.push_back({now[i].c, now[i].id});

        sort(up.begin(), up.end());
        sort(down.begin(), down.end());
        int qa = now[sz / 2].a;
        int qb = up[up.size() / 2].first;
        int qc = down[down.size() / 2].first;

        cout << "? " << qa << " " << qb << " " << qc << endl;

        string d;
        cin >> d;
        int d0, d1, d2;
        d0 = d[0] - '0';
        d1 = d[1] - '0';
        d2 = d[2] - '0';
        idx.clear();
        if (d0 == 1) {
            // 在上半部分
            if (d1 == 1) {
                for (int i = 0; i < up.size() / 2; i++) {
                    idx.push_back(up[i].second);
                }
            } else {
                for (int i = up.size() / 2; i < up.size(); i++) {
                    idx.push_back(up[i].second);
                }
            }
        } else {
            if (d2 == 1) {
                for (int i = 0; i < down.size() / 2; i++) {
                    idx.push_back(down[i].second);
                }
            } else {
                for (int i = down.size() / 2; i < down.size(); i++) {
                    idx.push_back(down[i].second);
                }
            }
        }

        // cout << "after:";
        // for (int x : idx)
        //     cout << x << ' ';
        // cout << endl;
    }
    cout << "! " << arr[idx[0]].a << ' ' << arr[idx[0]].b << ' '
         << arr[idx[0]].c << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
