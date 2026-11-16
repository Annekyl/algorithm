#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
const int N = 1e5 + 10;

// 一奇一偶循环放 满足奇数要求
// 怎么实现质数？
// 当前位置加下一个位置或减下一个位置 绝对值 奇数
// 1 2 3 		3 5
// 1 4 3 2 加偶数，跟最后一个偶数换位置		5 7 5
// 5 2 1 4 3 加奇数，和最后的偶数一起放到最前面		7 3 5 7
// 5 2 1 6 3 4		7 3 7 3 7
// 7 4 5 2 1 6 3

// 1 4 3 2 5
// 1 4 3 2 5 6
// 1 4 3 2 7 6 5
// 1 4 3 2 7 6 5 8

void get_primes(int n) {
    vector<bool> st(n + 1, false);
    vi prime;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            prime.push_back(i);
        }
        for (int j = 0; prime[j] <= n / i; j++) {
            st[prime[j] * i] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
    for (int x : prime)
        cout << x << ' ';
    cout << endl;
}

vector<vector<int>> pre = {{},
                           {1},
                           {1, 2},
                           {1, 2, 3},
                           {1, 2, 3, 4},
                           {1, 4, 3, 2, 5},
                           {5, 2, 1, 4, 3, 6},
                           {5, 6, 1, 2, 3, 4, 7},
                           {3, 6, 1, 4, 7, 2, 5, 8}};

void solve() {
    int n;
    cin >> n;
    if (n <= 8) {
        for (int i = 0; i < n; i++) {
            cout << pre[n][i] << ' ';
        }
        cout << endl;
    } else {
        int cnt = n / 8;
        rep(k, 0, cnt) {
            rep(i, 0, 8) { cout << pre[8][i] + k * 8 << ' '; }
        }
        int rem = n % 8;
        rep(i, 0, rem) { cout << pre[8][i] + cnt * 8 << ' '; }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // get_primes(30);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
