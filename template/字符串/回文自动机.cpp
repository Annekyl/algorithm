// 回文自动机 (Palindromic Tree / Eertree)
// AcWing 158. 回文子串的最大长度
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 3000010;

char s[N];
int n;

struct Node {
    int len, fail;
    int ch[26];
    int cnt;
} tr[N];

int last, idx;

void init() {
    tr[0].len = 0, tr[0].fail = 1;
    tr[1].len = -1, tr[1].fail = 1;
    last = 0;
    idx = 2;
}

int get_fail(int x, int len) {
    while (s[len - tr[x].len - 1] != s[len]) x = tr[x].fail;
    return x;
}

void insert(char c, int pos) {
    int cur = get_fail(last, pos);
    if (!tr[cur].ch[c - 'a']) {
        tr[++idx].len = tr[cur].len + 2;
        int fail = get_fail(tr[cur].fail, pos);
        tr[idx].fail = tr[fail].ch[c - 'a'];
        tr[cur].ch[c - 'a'] = idx;
    }
    last = tr[cur].ch[c - 'a'];
    tr[last].cnt++;
}

// 统计本质不同回文子串数
int count_distinct_palindromes() {
    return idx - 2;
}

// 获取所有回文子串的出现次数
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
