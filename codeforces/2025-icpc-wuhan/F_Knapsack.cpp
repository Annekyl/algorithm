#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
typedef __int128_t int128; // 使用 __int128 处理大数模运算

const int MOD = 998244353;

// 快速幂
ll power(ll base, ll exp, ll m) {
    ll res = 1;
    base %= m;
    while (exp > 0) {
        if (exp % 2 == 1) res = (ll)((int128)res * base % m);
        base = (ll)((int128)base * base % m);
        exp /= 2;
    }
    return res;
}

// 针对 __int128 的快速幂
ll power128(ll base, ll exp, int128 m) {
    int128 res = 1;
    int128 b = base % m;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * b) % m;
        b = (b * b) % m;
        exp /= 2;
    }
    return (ll)res;
}

void solve() {
    int n;
    ll m;
    if (!(cin >> n >> m)) return;

    map<ll, ll> counts;
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        counts[b] += a;
    }
    if (counts.find(0) == counts.end()) counts[0] = 0;

    vector<pair<ll, ll>> v;
    for (auto const& [b, a] : counts) v.push_back({b, a});

    int d = v.size();
    vector<ll> r(d);
    
    // 从高到低计算余数 r[j] = S_j % m
    r[d - 1] = v[d - 1].second % m;
    for (int i = d - 2; i >= 0; --i) {
        ll delta = v[i + 1].first - v[i].first;
        ll p2 = power(2, delta, m);
        r[i] = (ll)(((int128)r[i + 1] * p2 + v[i].second) % m);
    }

    // 从低到高计算低位物品对高位的“进位”影响
    vector<ll> C(d);
    vector<bool> has_rem(d);
    C[0] = 0;
    has_rem[0] = false;
    for (int i = 0; i < d - 1; ++i) {
        ll T = C[i] + v[i].second;
        ll delta = v[i + 1].first - v[i].first;
        if (delta >= 40) { // 2^40 > 10^12，足以容纳 m + a_i 的进位
            C[i + 1] = 0;
            has_rem[i + 1] = (T > 0) || has_rem[i];
        } else {
            C[i + 1] = T >> delta;
            has_rem[i + 1] = (T & ((1LL << delta) - 1)) > 0 || has_rem[i];
        }
    }

    // 寻找最大的 j 使得 K_j 是全局最大值
    int best_j = 0;
    for (int j = d - 1; j >= 0; --j) {
        bool ok = false;
        if (r[j] == 0) {
            if (C[j] == 0 && !has_rem[j]) ok = true;
        } else {
            if (C[j] + (has_rem[j] ? 1 : 0) <= m - r[j]) ok = true;
        }
        if (ok) {
            best_j = j;
            break;
        }
    }

    // 计算结果：使用 BIG_MOD = m * MOD 技巧处理大数除法取模
    int128 BIG_MOD = (int128)m * MOD;
    int128 current_S = v[d - 1].second % BIG_MOD;
    for (int i = d - 2; i >= best_j; --i) {
        ll delta = v[i + 1].first - v[i].first;
        ll p2 = power128(2, delta, BIG_MOD);
        current_S = (v[i].second + (int128)current_S * p2) % BIG_MOD;
    }
    
    ll q_best = (ll)(current_S / m);
    ll res_h = (q_best + (r[best_j] > 0 ? 1 : 0)) % MOD;
    ll ans = (ll)((int128)res_h * power(2, v[best_j].first, MOD) % MOD);
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}