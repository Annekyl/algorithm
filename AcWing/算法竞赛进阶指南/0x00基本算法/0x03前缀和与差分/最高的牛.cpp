#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int MAX_N = 5010;

int n, p, h, m;
int a[MAX_N];
int d[MAX_N];
map<pii, bool> existed;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> p >> h >> m;
    a[p] = h;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        // 区间[a,b]保证满足a<b
        if (a > b)
            swap(a, b);
        if (existed[make_pair(a, b)])
            continue;
        // 从a+1到b-1的身高均减去1
        d[a + 1]--;
        d[b]++;

        existed[make_pair(a, b)] = true;
    }

    // 从差分数组得到原数组
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + d[i];
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] + h << endl;
    }
    return 0;
}