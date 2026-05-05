#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e5 * 33;

int n;
int a[N];

int trie[N][2], tot = 1;
bool ed[N];

// 插入到trie树中
void insert(int x) {
    int p = 1;
    for (int i = 31; i >= 0; i--) {
        int bit = (x >> i) & 1;
        if (trie[p][bit] == 0)
            trie[p][bit] = ++tot;
        p = trie[p][bit];
    }
    ed[p] = true;
}

// 返回最大异或和
int search(int x) {
    int p = 1;
    int ret = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = (x >> i) & 1;
        if (trie[p][bit ^ 1] != 0) {
            p = trie[p][bit ^ 1];
            ret += (1 << i);
        } else {
            p = trie[p][bit];
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        insert(a[i]);
        ans = max(ans, search(a[i]));
    }
    cout << ans;
    return 0;
}