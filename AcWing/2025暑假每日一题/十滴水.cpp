#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 3e5 + 10;

int c, m, n;
pii a[N];
int l[N], r[N], w[N];
unordered_map<int, int> rec;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + m + 1);
    // for (int i = 1; i <= m; i++) {
    //     auto p = a[i];
    //     cout << p.first << " " << p.second << endl;
    // }
    for (int i = 1; i <= m; i++) {
        l[i] = i - 1, r[i] = i + 1;
        w[i] = a[i].second;
        rec[a[i].first] = i;
        // rec.insert(make_pair(a[i].first, i));
    }
    // for (auto p : rec) {
    //     cout << p.first << " " << p.second << endl;
    // }
    int ans = m;
    while (n--) {
        int p;
        cin >> p;
        // cout << p << endl;
        int idx = rec[p];
        // cout << "idx:" << idx << endl;
        a[idx].second++;
        // cout << "idx.second:" << a[idx].second << endl;
        while (a[idx].second >= 5) {
            ans--;
            int pos = 0;
            int left = l[idx], right = r[idx]; // 记录当前左右节点的索引
            r[left] = right, l[right] = left;  // 删除当前节点

            // 先判断是否越界再相加，防止多次给越界位置相加导致达到5
            if (right <= m && ++a[right].second >= 5)
                pos = right;
            if (left > 0 && ++a[left].second >= 5)
                pos = left;
            idx = pos;
        }
        cout << ans << endl;
    }
    return 0;
}