#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define DEBUG

#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << '\n'
#else
#define debug(x)
#endif

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int N = 2e5 + 10;
const int mod = 998244353;

int n;

int fact[N], infact[N];

int qmi(int a, int b, int p) {
    int res = 1;
    a %= p;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void pre_calc() {
    fact[0] = 1;
    infact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % mod;
        infact[i] = infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
}

struct Node {
    int val, mx, mn;
    int dp;
};

void solve() {
    cin >> n;
    vector<Node> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].val;
    }

    vector<int> g[n + 1];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    function<void(int, int)> dfs = [&](int u, int fa) {
        // 初始化当前节点的最大值、最小值、概率
        auto &node = a[u];
        node.mn = a[u].val;
        node.mx = a[u].val;
        node.dp = 1;

        vector<int> childen;
        for (int v : g[u]) {
            if (v == fa)
                continue;
            dfs(v, u);
            childen.push_back(v);
        }

        // 到叶子节点，直接退出
        if (childen.size() == 0)
            return;

        // 更新当前节点的最小值，最大值和概率
        for (int v : childen) {
            if (a[v].dp == 0 || node.val > a[v].mn) {
                node.dp = 0;
            }
            node.mn = min(node.mn, a[v].mn);
            node.mx = max(node.mx, a[v].mx);
            node.dp = node.dp * a[v].dp % mod;
        }

        if (node.dp == 0)
            return;

        sort(childen.begin(), childen.end(), [&](int x, int y) {
            if (a[x].mn != a[y].mn)
                return a[x].mn < a[y].mn;
            return a[x].mx < a[y].mx;
        });

        // 检查是否满足单调不减
        for (int i = 1; i < childen.size(); i++) {
            if (a[childen[i]].mn < a[childen[i - 1]].mx) {
                node.dp = 0;
                return;
            }
        }

        // 检查相邻的节点能否互换
        int validsz = 1;
        for (int i = 0; i < childen.size();) {
            int j = i;
            while (j < childen.size() && a[childen[j]].mn == a[childen[i]].mn &&
                   a[childen[j]].mx == a[childen[i]].mx) {
                j++;
            }
            if (a[childen[i]].mx == a[childen[i]].mn) {
                validsz = validsz * fact[j - i] % mod;
            }
            i = j;
        }

        // 更新最终的概率值
        node.dp = node.dp * validsz % mod;
        node.dp = node.dp * infact[childen.size()] % mod;
    };

    dfs(1, 0);
    cout << a[1].dp << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pre_calc();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
