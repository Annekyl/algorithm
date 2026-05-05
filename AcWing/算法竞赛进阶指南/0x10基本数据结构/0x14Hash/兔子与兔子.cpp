// #include "bits/stdc++.h"
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e6 + 10;

char s[N];
int m;
ull f[N]; // 字符串前缀哈希
ull p[N]; // 当前哈希值的大小

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    cin >> s + 1;
    cin >> m;
    // scanf("%s", s + 1);
    // scanf("%d", &m);
    // 预处理字符串前缀
    p[0] = 1;
    // 字符串长度要用变量存下来，否则每次循环调用strlen，时间复杂度会到O(n^2)
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * 131 + (s[i] - 'a' + 1);
        p[i] = p[i - 1] * 131;
    }
    while (m--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        // scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (f[r1] - f[l1 - 1] * p[r1 - l1 + 1] ==
            f[r2] - f[l2 - 1] * p[r2 - l2 + 1]) {
            cout << "Yes" << endl;
            // puts("Yes");
        } else {
            cout << "No" << endl;
            // puts("No");
        }
    }

    return 0;
}