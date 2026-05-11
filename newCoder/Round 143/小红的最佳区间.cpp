#include "bits/stdc++.h"
#define int long long

using namespace std;

struct Event {
    int pos, type;
    bool operator<(const Event &other) const {
        if (pos != other.pos)
            return pos < other.pos;
        return type < other.type;
    }
};

signed main() {
    int n, k;
    cin >> n >> k;
    vector<Event> a;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a.push_back({l - k, 1});
        a.push_back({r + 1, -1});
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int cur = 0;
    for (auto [pos, type] : a) {
        cur += type;
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}