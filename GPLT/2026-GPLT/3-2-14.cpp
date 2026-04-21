#include "bits/stdc++.h"
#define int long long
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

typedef pair<int, int> pii;

void solve() {
    int n;
    cin >> n;

    int reduce = 0;
    map<int, int> red, blue;              // 编号->出现次数
    map<int, vector<int>> r_to_b, b_to_r; // 编号->对应另一种颜色的编号数组
    for (int i = 0; i < n; i++) {
        int r, b;
        cin >> r >> b;
        red[r]++;
        blue[b]++;
        r_to_b[r].push_back(b);
        b_to_r[b].push_back(r);
    }
    priority_queue<pii> red_cnt, blue_cnt;
    for (auto [id, c] : red) {
        red_cnt.push({c, id});
    }

    // cout << red_cnt.top().first << " " << red_cnt.top().second << endl;

    while (red_cnt.size() && red_cnt.top().first > 1) {
        auto [c, id] = red_cnt.top();
        red_cnt.pop();
        reduce += c - 1;
        auto arr = r_to_b[id];
        for (auto x : arr) {
            blue[x]--;
        }
    }

    for (auto [id, c] : blue) {
        blue_cnt.push({c, id});
    }

    while (blue_cnt.size() && blue_cnt.top().first > 1) {
        auto [c, id] = blue_cnt.top();
        blue_cnt.pop();
        reduce += c - 1;
        auto arr = b_to_r[id];
        for (auto x : arr) {
            red[x]--;
        }
    }

    cout << n * 2 - reduce << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
