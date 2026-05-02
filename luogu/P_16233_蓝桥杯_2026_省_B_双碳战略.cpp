#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define DEBUG

#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << '\n'
#else
#define debug(x)
#endif

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;
const int mod = 998244353;

int n;

int fact[N], infact[N];
int qmi(int a, int b, int p) {
    int res = 1;
    a %= p;
    while (b) {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

void calc(int n) {
    fact[0] = 1;
    infact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % mod;
        infact[i] = infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
}

int C(int k, int n) {
    return ((fact[n] * infact[k] % mod) * infact[n - k]) % mod;
}

void solve() {
    // cin >> n;
    // vector<int> a(n, 0);
    // map<vector<int>, int> d;
    // queue<vector<int>> q;
    // d[a] = 0;
    // q.push(a);
    // while (q.size()) {
    //     auto t = q.front();
    //     q.pop();
    //     vector<int> temp(n);
    //     if (d[t] + 1 & 1) {
    //         // 奇数次
    //         for (int i = 0; i < n; i++) { // 从第几位开始进行翻转
    //             for (int j = 0; j < n; j++) {
    //                 if (j < i)
    //                     temp[j] = t[j];
    //                 else
    //                     temp[j] = t[j] ^ 1;
    //             }
    //             if (d.find(temp) == d.end()) {
    //                 d[temp] = d[t] + 1;
    //                 q.push(temp);
    //             }
    //         }
    //     } else {
    //         // 偶数次
    //         for (int i = 0; i < n; i++) { // 从第几位开始进行翻转
    //             for (int j = 0; j < n; j++) {
    //                 if (j <= i)
    //                     temp[j] = t[j] ^ 1;
    //                 else
    //                     temp[j] = t[j];
    //             }
    //             if (d.find(temp) == d.end()) {
    //                 d[temp] = d[t] + 1;
    //                 q.push(temp);
    //             }
    //         }
    //     }
    // }

    // for (auto [arr, step] : d) {
    //     for (auto x : arr)
    //         cout << x << ' ';
    //     cout << ":" << step << endl;
    // }

    n = 2026;
    calc(2026);
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = (ans + (C(i, 2026) * i % mod)) % mod;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
