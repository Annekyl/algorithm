#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<string, int> psi;

constexpr int INF = 0x3f3f3f3f;
constexpr int MAX_N = 1e5 + 10;

int n, m;
psi a[MAX_N];

int calc(int bit, int now) {
    for (int i = 1; i <= n; i++) {
        // 提取当前存储的数的第bit位的具体值
        int x = a[i].second >> bit & 1;
        if (a[i].first == "AND")
            now &= x;
        else if (a[i].first == "OR")
            now |= x;
        else
            now ^= x;
    }
    return now;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string op;
        int t;
        cin >> op >> t;
        a[i] = make_pair(op, t);
    }

    // val:当前构造的值
    // ans:最终结果
    int val = 0, ans = 0;
    // 第29位的权值是2^28次方，大于2*10^9，满足题目要求
    for (int bit = 29; bit >= 0; bit--) {
        // 计算该位设为0和1时的结果
        int res0 = calc(bit, 0);
        int res1 = calc(bit, 1);

        // 如果设为1不会超过m，且设为1的结果更好
        // 贪心策略
        // 判断当前位选1是否能带来更大的收益​
        // ​在不超过 m 的前提下，尽量选择能优化结果的位​
        // ​如果选0和选1效果相同，优先选0以保留剩余空间
        if (val + (1 << bit) <= m && res0 < res1) {
            val += 1 << bit, ans += res1 << bit;
        } else {
            // 否则设为0
            ans += res0 << bit;
        }
    }
    cout << ans << endl;
    return 0;
}