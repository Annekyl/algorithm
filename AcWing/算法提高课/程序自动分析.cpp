#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 2e5 + 10;

class Discretizer {
  private:
    vector<int> sorted_unique;
    bool is_sorted = false;

  public:
    // 添加需要离散化的值
    void add(int x) {
        sorted_unique.push_back(x);
        is_sorted = false;
    }

    // 预处理排序去重
    void prepare() {
        sort(sorted_unique.begin(), sorted_unique.end());
        sorted_unique.erase(unique(sorted_unique.begin(), sorted_unique.end()),
                            sorted_unique.end());
        is_sorted = true;
    }

    // 获取离散化后的值（从1开始）
    int get_rank(int x) {
        if (!is_sorted)
            prepare();
        return lower_bound(sorted_unique.begin(), sorted_unique.end(), x) -
               sorted_unique.begin() + 1;
    }

    // 获取原始值（根据离散化后的rank）
    int get_original(int rank) {
        if (!is_sorted)
            prepare();
        return sorted_unique[rank - 1];
    }

    // 获取离散化后的范围大小
    int size() {
        if (!is_sorted)
            prepare();
        return sorted_unique.size();
    }
};

int fa[N];

void init() {
    for (int i = 0; i < N; i++) {
        fa[i] = i;
    }
}

int get(int x) {
    if (x == fa[x])
        return x;
    return fa[x] = get(fa[x]);
}

void merge(int x, int y) {
    x = get(x), y = get(y);
    if (x == y)
        return;
    fa[x] = y;
}

void solve() {
    init();
    int n;
    cin >> n;
    vector<pii> eq, diff;
    Discretizer arr;
	// 离散化值域
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        arr.add(x);
        arr.add(y);
        if (z == 1)
            eq.push_back({x, y});
        else
            diff.push_back({x, y});
    }

	// 并查集合并
    for (auto [x, y] : eq) {
        x = arr.get_rank(x), y = arr.get_rank(y);
        merge(x, y);
    }

    bool suc = true;
    for (auto [x, y] : diff) {
        x = arr.get_rank(x), y = arr.get_rank(y);
        if (get(x) == get(y)) {
            suc = false;
            break;
        }
    }
    cout << (suc ? "YES" : "NO") << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
