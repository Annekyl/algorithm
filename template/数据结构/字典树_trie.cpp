// 字典树 (Trie)
// AcWing 142. 前缀统计 / 143. 最大异或对
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, S = 1000010;

int n, m;
int tr[N * 32][2], idx; // 二进制字典树

void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        if (!tr[p][u]) tr[p][u] = ++idx;
        p = tr[p][u];
    }
}

int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        if (tr[p][!u]) {
            res += 1 << i;
            p = tr[p][!u];
        } else {
            p = tr[p][u];
        }
    }
    return res;
}

// 字符串Trie (用于字符串前缀匹配)
const int M = 100010;
int tr2[M][26], cnt2[M], idx2;

void insert_str(string s) {
    int p = 0;
    for (char c : s) {
        int u = c - 'a';
        if (!tr2[p][u]) tr2[p][u] = ++idx2;
        p = tr2[p][u];
    }
    cnt2[p]++;
}

int query_str(string s) {
    int p = 0;
    for (char c : s) {
        int u = c - 'a';
        if (!tr2[p][u]) return 0;
        p = tr2[p][u];
    }
    return cnt2[p];
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
