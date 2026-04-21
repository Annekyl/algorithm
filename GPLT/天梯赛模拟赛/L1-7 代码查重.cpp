#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;
    map<int, pair<int, string>> mp; // 题目编号，分数，提交时间
    for (int i = 0; i < n; i++) {
        int id, sc;
        string t1, t2, t;
        cin >> t1 >> t2 >> id >> sc;
        t = t1 + " " + t2;
        if (mp.find(id) == mp.end()) {
            mp[id] = {sc, t};
        } else {
            if (mp[id].first < sc) {
                mp[id] = {sc, t};
            }
        }
    }
    vector<tuple<string, int, int>> res;
    for (auto [id, temp] : mp) {
        auto [sc, t] = temp;
        res.push_back({t, id, sc});
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        auto [t, id, sc] = res[i];
        cout << t << " " << id << " " << sc << endl;
    }
    return 0;
}