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
constexpr int N = 3e5 + 10;

/*
注意N的大小，要大于3e5，开小了会错
*/

int n, m;
pii query[N], op[N]; // 查询，添加
vi a;                // 全部需要离散化的坐标 0-based
int val[N];          // 离散化后的坐标上的具体值 1-based
int s[N];

int find(int x) {
    int l = 0, r = a.size() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l + 1; // 0-based转1-based
}

void solve() {
    cin >> n >> m;
    FOR(i, 1, n) {
        int x, c;
        cin >> x >> c;
        op[i] = {x, c};
        a.push_back(x);
    }

    FOR(i, 1, m) {
        int l, r;
        cin >> l >> r;
        query[i] = {l, r};
        a.push_back(l);
        a.push_back(r);
    }

    // 将离散坐标排序
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    // 处理加法操作
    FOR(i, 1, n) {
        auto &[x, c] = op[i];
        int idx = find(x);
        val[idx] += c;
    }

    // 计算前缀和
    FOR(i, 1, a.size()) { s[i] = s[i - 1] + val[i]; }

    // 处理查询
    FOR(i, 1, m) {
        auto &[l, r] = query[i];
        int lidx = find(l);
        int ridx = find(r);
        cout << s[ridx] - s[lidx - 1] << endl;
    }
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