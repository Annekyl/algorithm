#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e6 + 10;

int n, m;
char temp[N];
int ans;

int trie[N][26], tot = 1;
int cnt[N];

void insert(char *s) {
    int len = strlen(s), p = 1;
    for (int i = 0; i < len; i++) {
        int c = s[i] - 'a';
        if (trie[p][c] == 0)
            trie[p][c] = ++tot;
        p = trie[p][c];
    }
    cnt[p]++;
}

int search(char *s) {
    int len = strlen(s), p = 1;
    int ans = 0;
    for (int i = 0; i < len; i++) {
        p = trie[p][s[i] - 'a'];
        if (p == 0)
            return ans;
        ans += cnt[p];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        insert(temp);
    }
    for (int i = 1; i <= m; i++) {
        cin >> temp;
        ans = 0;
        cout << search(temp) << endl;
    }
    return 0;
}