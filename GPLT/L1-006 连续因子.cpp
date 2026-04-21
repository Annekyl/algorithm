// #include "bits/stdc++.h"

// #define int long long
// #define FOR(i, a, b) for (int i = (a); i <= (b); i++)
// #define REF(i, a, b) for (int i = (a); i >= (b); i--)

// using namespace std;

// typedef long long ll;
// typedef pair<int, int> pii;
// typedef vector<int> vi;
// typedef vector<bool> vb;

// constexpr int INF = 0x3f3f3f3f3f3f3f3f;
// constexpr int mod = 999991;
// constexpr int N = 1e5 + 10;

// int n;

// void solve() {
//     cin >> n;
//     int st = 2, ed = 2;
//     int mul = 2;
//     while (1) {
//         if (mul < n) {
//             mul *= ++ed;
//         } else if (mul > n) {
//             mul /= st++;
//         } else {
//             break;
//         }
//     }
//     cout << ed - st + 1 << endl;
//     FOR(i, st, ed) {
//         cout << i;
//         if (i != ed)
//             cout << "*";
//     }
// }

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t = 1;
//     // cin>>t;
//     while (t--) {
//         solve();
//     }
//     return 0;
// }

#include "bits/stdc++.h"
#define int long long

using namespace std;

signed main() {
    int n;
    cin >> n;
    int mx = 0;
    int mx_st = 0;
    for (int st = 2; st * st <= n; st++) {
        int mul = 1;
        int len = 0;
        for (int i = st; i <= n; i++) {
            if (n % (mul * i))
                break;
            len++;
            mul *= i;
            if (len > mx) {
                mx = len;
                mx_st = st;
            }
        }
    }
    if (mx != 0) {  // ⚠️特判质数
        cout << mx << endl;
        for (int i = mx_st; i < mx_st + mx; i++) {
            if (i != mx_st)
                cout << "*";
            cout << i;
        }
    } else {
        cout << 1 << endl << n;
    }

    return 0;
}