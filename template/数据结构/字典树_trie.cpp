// 字典树 (Trie / Prefix Tree)
// AcWing 142. 前缀统计 / 143. 最大异或对
// 一种树形数据结构，用于高效存储和检索字符串/数字集合
// 支持操作：
//   1. 插入元素
//   2. 查询与给定值的最大异或值
// 时间复杂度：插入和查询均为 O(L)，L 为元素长度（位数或字符数）
// 空间复杂度：O(N * L)，N 为元素个数

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, S = 1000010;

int n, m;
int tr[N * 32][2], idx; // 二进制字典树，每个节点有两个子节点（0和1）

// 插入数字 x 到字典树
// 从最高位（第30位）开始，逐位构建路径
void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1; // 取第 i 位
        if (!tr[p][u]) tr[p][u] = ++idx;
        p = tr[p][u];
    }
}

// 查询与 x 异或值最大的数
// 贪心策略：从高位到低位，尽量走与 x 当前位不同的分支
int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        if (tr[p][!u]) {       // 如果存在相反位，走那边（异或得1）
            res += 1 << i;
            p = tr[p][!u];
        } else {                // 否则走相同位
            p = tr[p][u];
        }
    }
    return res;
}

// 字符串 Trie（用于字符串前缀匹配）
const int M = 100010;
int tr2[M][26], cnt2[M], idx2; // 26个小写字母

// 插入字符串 s
void insert_str(string s) {
    int p = 0;
    for (char c : s) {
        int u = c - 'a';
        if (!tr2[p][u]) tr2[p][u] = ++idx2;
        p = tr2[p][u];
    }
    cnt2[p]++; // 标记字符串结尾，计数加1
}

// 查询字符串 s 出现的次数
int query_str(string s) {
    int p = 0;
    for (char c : s) {
        int u = c - 'a';
        if (!tr2[p][u]) return 0; // 不存在该前缀
        p = tr2[p][u];
    }
    return cnt2[p]; // 返回以 s 结尾的字符串数量
}

int main() {
    scanf("%d%d", &n, &m);
    while (n--) {
        int x;
        scanf("%d", &x);
        insert(x);
    }

    int res = 0;
    while (m--) {
        int x;
        scanf("%d", &x);
        res = max(res, query(x));
    }

    printf("%d\n", res);

    return 0;
}
