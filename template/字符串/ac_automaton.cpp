#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 10010, S = 55;

int n;
int tr[N * S][26], cnt[N * S], idx;
int fail[N * S];
char str[S];

void insert() {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!tr[p][u]) tr[p][u] = ++idx;
        p = tr[p][u];
    }
    cnt[p]++;
}

void build() {
    queue<int> q;
    for (int i = 0; i < 26; i++)
        if (tr[0][i]) q.push(tr[0][i]);

    while (q.size()) {
        int t = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            int p = tr[t][i];
            if (!p) tr[t][i] = tr[fail[t]][i];
            else {
                fail[p] = tr[fail[t]][i];
                q.push(p);
            }
        }
    }
}

int query() {
    int res = 0;
    int p = 0;
    for (int i = 0; str[i]; i++) {
        p = tr[p][str[i] - 'a'];
        for (int j = p; j; j = fail[j])
            res += cnt[j];
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
