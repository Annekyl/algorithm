#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 5e6 + 10;

int n, m;
int a[N];       // 输入数据
bool is_set[N]; // 是否在输入中
bool v[N];      // 该数是否访问过
int mask;       // 掩码

void dfs(int x) {
    if (v[x])
        return;
    v[x] = true;

    if (is_set[x]) {
        dfs(x ^ mask);
    }

    int temp = x;
    while (temp) {
        int low_bit = temp & (-temp);
        dfs(x - low_bit);
        temp -= low_bit;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> m) {
        memset(is_set, 0, sizeof is_set);
        memset(v, 0, sizeof v);
        mask = (1 << n) - 1;
        int res = 0;
        bool zero = false;

        for (int i = 1; i <= m; i++) {
            cin >> a[i];
            is_set[a[i]] = true;
            if (a[i] == 0)
                zero = true;
        }

        if (zero) {
            res = 1;
        } else {
            for (int i = 1; i <= m; i++) {
                if (!v[a[i]]) {
                    dfs(a[i] ^ mask);
                    res++;
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}