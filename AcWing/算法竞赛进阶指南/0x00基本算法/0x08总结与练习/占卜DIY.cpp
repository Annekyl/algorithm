#include "bits/stdc++.h"

#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

unordered_map<char, int> mp = {
    {'A', 1}, {'2', 2}, {'3', 3},  {'4', 4},  {'5', 5},  {'6', 6},  {'7', 7},
    {'8', 8}, {'9', 9}, {'0', 10}, {'J', 11}, {'Q', 12}, {'K', 13},
};

int n;
deque<int> a[15]; // 牌堆
int cnt[15];      // 统计每张牌被翻出来几张

void open(int idx) {
    if (idx == 13)
        return;
    a[idx].push_front(idx);
    cnt[idx]++;

    // 取出当前堆的最后一张牌
    int x = a[idx].back();
    a[idx].pop_back();

    // 放置最后一张牌
    open(x);
}

void solve() {
    FOR(i, 1, 13) {
        FOR(j, 1, 4) {
            char x;
            cin >> x;
            a[i].push_back(mp[x]);
        }
    }
    FOR(i, 1, 4) {
        // cout << "i:" << i << endl;
        // 取出生命牌的第一张
        int idx = a[13].front();
        // cout << "idx:" << idx << endl;
        a[13].pop_front();
        open(idx);
    }

    int ans = 0;
    FOR(i, 1, 12) {
        // cout << cnt[i] << " ";
        if (cnt[i] == 4)
            ans++;
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}