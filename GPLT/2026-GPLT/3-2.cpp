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

    // while (red_cnt.size() && red_cnt.top().first > 1) {
    //     auto [c, id] = red_cnt.top();
    //     red_cnt.pop();
    //     reduce += c - 1;
    //     auto arr = r_to_b[id];
    //     for (auto x : arr) {
    //         blue[x]--;
    //     }
    // }

    for (auto [id, c] : blue) {
        blue_cnt.push({c, id});
    }

    // while (blue_cnt.size() && blue_cnt.top().first > 1) {
    //     auto [c, id] = blue_cnt.top();
    //     blue_cnt.pop();
    //     reduce += c - 1;
    //     auto arr = b_to_r[id];
    //     for (auto x : arr) {
    //         red[x]--;
    //     }
    // }

    // int debug_cnt = 0;
    while (1) {
        // for (auto [id, c] : red)
        //     red_cnt.push({c, id});
        // for (auto [id, c] : blue)
        //     blue_cnt.push({c, id});
        auto [c1, id1] = red_cnt.top();
        red_cnt.pop();
        // red.erase(id1);
        auto [c2, id2] = blue_cnt.top();
        blue_cnt.pop();
        // blue.erase(id2);
        int c, id;
        bool run1;
        if (c1 >= c2) {
            c = c1, id = id1;
            run1 = true;
            red.erase(id);
            // cout << "red ";
            // cout << id << ":" << c << endl;
            // cout << red[id] << " ";
        } else {
            c = c2, id = id2;
            run1 = false;
            blue.erase(id);
            // cout << "blue ";
            // cout << id << ":" << c << endl;
        }

        // debug(c);
        // debug(id);

        if (c < 2)
            break;
        if (run1) {
            reduce += c - 1;
            auto arr = r_to_b[id];
            for (auto x : arr) {
                blue[x]--;
            }
            while (blue_cnt.size())
                blue_cnt.pop();
            for (auto [id, c] : blue) {
                blue_cnt.push({c, id});
            }
        } else {
            reduce += c - 1;
            auto arr = b_to_r[id];
            for (auto x : arr) {
                red[x]--;
            }
            while (red_cnt.size())
                red_cnt.pop();
            for (auto [id, c] : red) {
                red_cnt.push({c, id});
            }
        }
        // if (++debug_cnt == 10)
        //     break;
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
