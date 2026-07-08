// 回文自动机 (Palindromic Tree / Eertree)
// AcWing 158. 回文子串的最大长度
// 用于高效处理字符串的回文子串相关问题
// 支持操作：
//   1. 统计本质不同回文子串数
//   2. 统计每个回文子串的出现次数
// 时间复杂度：O(n) 构建，O(1) 查询
// 核心结构：
//   - 两个根节点：长度为 -1（奇根）和 0（偶根）
//   - fail 指针：指向当前回文串的最长真回文后缀
//   - 节点存储：len（长度）、fail（回文后缀指针）、ch（转移）、cnt（出现次数）

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 3000010;

char s[N];
int n;

struct Node {
    int len, fail;       // len: 回文串长度, fail: 最长真回文后缀
    int ch[26];          // 字符转移
    int cnt;             // 该回文串的出现次数
} tr[N];

int last, idx; // last: 上一个插入的字符对应的回文串节点, idx: 节点计数

// 初始化：创建奇根（len=-1）和偶根（len=0）
// 奇根用于处理奇数长度回文，偶根用于处理偶数长度回文
void init() {
    tr[0].len = 0, tr[0].fail = 1;  // 偶根的 fail 指向奇根
    tr[1].len = -1, tr[1].fail = 1; // 奇根的 fail 指向自己
    last = 0;
    idx = 2;
}

// 获取 fail 指针：沿 fail 链回退，直到找到可以扩展的回文串
// 通过比较当前位置和回文串长度来判断是否可以扩展
int get_fail(int x, int len) {
    while (s[len - tr[x].len - 1] != s[len]) x = tr[x].fail;
    return x;
}

// 插入字符 c，构建回文自动机
// 1. 通过 fail 链找到可以扩展的回文串 cur
// 2. 如果 cur 没有 c 的转移，创建新节点
// 3. 新节点的 fail 指针通过 get_fail 找到
void insert(char c, int pos) {
    int cur = get_fail(last, pos);
    if (!tr[cur].ch[c - 'a']) {
        tr[++idx].len = tr[cur].len + 2; // 新回文串长度 = cur的长度 + 2
        int fail = get_fail(tr[cur].fail, pos);
        tr[idx].fail = tr[fail].ch[c - 'a']; // 设置 fail 指针
        tr[cur].ch[c - 'a'] = idx;
    }
    last = tr[cur].ch[c - 'a'];
    tr[last].cnt++; // 计数加1
}

// 统计本质不同回文子串数
// 节点数减去两个根节点
int count_distinct_palindromes() {
    return idx - 2;
}

// 获取所有回文子串的出现次数
// 通过 fail 树上传计数（类似拓扑排序）
// 短的回文串是长的回文串的真后缀，计数应该累加
void get_occurrences() {
    for (int i = idx - 1; i >= 2; i--)
        tr[tr[i].fail].cnt += tr[i].cnt;
}

int main() {
    init();

    scanf("%s", s + 1);
    n = strlen(s + 1);

    for (int i = 1; i <= n; i++) {
        insert(s[i], i);
    }

    printf("%d\n", count_distinct_palindromes());

    get_occurrences();
    for (int i = 2; i <= idx; i++) {
        if (tr[i].cnt > 0)
            printf("%d %d\n", tr[i].len, tr[i].cnt);
    }

    return 0;
}
