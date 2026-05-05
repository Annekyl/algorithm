#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip> // 用于格式化输出
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define int long long
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;
constexpr int M = 2e5 + 10;

int n, m;
int fa[N];

struct Edge {
    int x, y, z;
    bool operator<(const Edge &other) const { return z < other.z; }
} edge[M];

void init() { FOR(i, 1, n) fa[i] = i; }

int find(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) { fa[find(x)] = find(y); }

void solve() {
    cin >> n >> m;
    FOR(i, 1, m) {
        int x, y, z;
        cin >> x >> y >> z;
        edge[i] = {x, y, z};
    }
    sort(edge + 1, edge + m + 1);

    init();

    int ans = 0;
    int cnt = 0;
    FOR(i, 1, m) {
        auto &[x, y, z] = edge[i];
        if (find(x) != find(y)) {
            merge(x, y);
            cnt++;
            ans += z;
        }
    }
    if (cnt == n - 1) {
        cout << ans;
    } else {
        cout << "impossible";
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