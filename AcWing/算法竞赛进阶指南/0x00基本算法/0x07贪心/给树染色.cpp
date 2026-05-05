#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1010;

int n, r;      // n：节点数量，r：根节点
int a[N];      // 节点权值
int fa[N];     // 父节点
int v[N];      // 标记节点是否访问过
int ne[N];     // 下一个节点
int lst[N];    // 当前节点所在块的最后一个节点
int cnt[N];    // 当前块的节点数量
int sum[N];    // 当前块的总权值
double avg[N]; // 当前块的平均权值

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ne[i] = i;
        lst[i] = i;
        cnt[i] = 1;
        sum[i] = a[i];
        avg[i] = a[i];
    }

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        fa[y] = x;
    }

    // 处理除根节点外的其他节点
    for (int i = 1; i < n; i++) {
        int idx = 0;
        double w = 0;

        // 找当前未访问过的平均权值最大的节点
        for (int j = 1; j <= n; j++) {
            if (j != r && !v[j] && w < avg[j]) {
                idx = j, w = avg[j];
            }
        }

        // 与当前未访问过的父节点相连
        int f = fa[idx];
        while (v[f]) {
            f = fa[f];
            fa[idx] = f;
        }

        // 将两块相接
        ne[lst[f]] = idx;
        lst[f] = lst[idx];
        cnt[f] += cnt[idx];
        sum[f] += sum[idx];
        avg[f] = (double)sum[f] / cnt[f];
        v[idx] = 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += i * a[r];
        r = ne[r];
    }
    cout << ans << endl;
    return 0;
}