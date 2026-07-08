// 二分图匹配 (Bipartite Matching)
// 匈牙利算法 / 最大流求二分图匹配
// AcWing 861. 二分图的最大匹配
// 二分图：将顶点分成两组，所有边都连接不同组的顶点
// 匈牙利算法：用于求解二分图最大匹配
// 时间复杂度：O(nm)，n 为左部点数，m 为边数
// 核心思想：增广路算法，每次为一个左部点寻找匹配
//   1. 遍历左部点的所有邻接右部点
//   2. 如果右部点未匹配，直接匹配
//   3. 如果右部点已匹配，尝试让原匹配者寻找其他匹配（递归）

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m; // n1: 左部点数, n2: 右部点数, m: 边数
int h[N], e[M], ne[M], idx; // 邻接表（只存左部到右部的边）
int match[N]; // match[j] = i: 右部点 j 当前匹配的左部点 i
bool st[N];   // st[j]: 本轮 DFS 中右部点 j 是否已被访问过

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 为左部点 u 寻找匹配
// 返回 true 表示找到了增广路
bool find(int u) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (!st[v]) {
            st[v] = true;
            if (match[v] == 0 || find(match[v])) {
                match[v] = u; // 更新匹配
                return true;
            }
        }
    }
    return false;
}

// 匈牙利算法
// 依次为每个左部点寻找匹配
int hungarian() {
    int res = 0;
    for (int i = 1; i <= n1; i++) {
        memset(st, false, sizeof st); // 每轮重置访问标记
        if (find(i)) res++;
    }
    return res;
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d%d", &n1, &n2, &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    printf("%d\n", hungarian());

    return 0;
}
