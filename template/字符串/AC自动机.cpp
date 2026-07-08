// AC自动机 (Aho-Corasick Automaton)
// 用于多模式串匹配，在文本串中同时查找多个模式串
// 时间复杂度：构建 O(Σ|p_i|)，查询 O(|s| + 匹配数)
// 核心思想：将多个模式串构建成 Trie + fail 指针（类似 KMP 的 next 数组）
// fail 指针：指向当前节点的最长真后缀对应的 Trie 节点
// 查询时，沿 fail 指针链收集所有匹配

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 10010, S = 55;

int n;
int tr[N * S][26], cnt[N * S], idx; // Trie 数组，cnt: 以该节点结尾的模式串数量
int fail[N * S];                     // fail 指针
char str[S];

// 插入模式串到 Trie
void insert() {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!tr[p][u]) tr[p][u] = ++idx;
        p = tr[p][u];
    }
    cnt[p]++; // 标记模式串结尾
}

// 构建 fail 指针（BFS 构建）
// fail 指针的含义：从根到 fail[p] 的字符串是根到 p 的字符串的最长真后缀
// 构建方法：BFS 遍历 Trie，对于每个节点的每个子节点，通过 fail 指针回退
void build() {
    queue<int> q;
    for (int i = 0; i < 26; i++)
        if (tr[0][i]) q.push(tr[0][i]); // 根的子节点入队

    while (q.size()) {
        int t = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            int p = tr[t][i];
            if (!p) tr[t][i] = tr[fail[t]][i]; // 没有子节点，直接指向 fail 的子节点
            else {
                fail[p] = tr[fail[t]][i]; // 设置 fail 指针
                q.push(p);
            }
        }
    }
}

// 查询文本串中模式串的匹配次数
// 在 Trie 上匹配文本串，每到达一个节点就沿 fail 指针链收集匹配
int query() {
    int res = 0;
    int p = 0;
    for (int i = 0; str[i]; i++) {
        p = tr[p][str[i] - 'a'];
        for (int j = p; j > 0 && cnt[j] != -1; j = fail[j]) // 沿 fail 指针链回溯
            res += cnt[j];
			cnt[j] = -1; // 【核心卡常技巧】标记为 -1，防止后续重复累加和重复遍历
			// eg: 字典里有 1000 个词：a, aa, aaa, ... , 一直到 1000 个 a。
			// 文本串长达 100,000，全是 aaaaaaaaaa...
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        insert();
    }

    build();

    scanf("%s", str);
    printf("%d\n", query());

    return 0;
}
