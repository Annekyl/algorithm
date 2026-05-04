#include "bits/stdc++.h"

#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

void solve() {
    int a, b, n, s;
    cin >> a >> b >> n >> s;
    if (a > b)
        swap(a, b);

    // s不是a的倍数
    if (s % a != 0) {
        cout << "YES" << endl;
        FOR(i, 1, n) cout << a << " ";
        cout << endl;
        return;
    }

    // s不是b的倍数
    if (s % b != 0) {
        cout << "YES" << endl;
        FOR(i, 1, n) cout << b << " ";
        cout << endl;
        return;
    }

    // s既是a的倍数也是b的倍数
    if (s == b) {
        if (n * a < b) {
            cout << "YES" << endl;
            FOR(i, 1, n) cout << a << ' ';
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }

    if (b % a != 0) {
        // b不是a的倍数，构造循环块
        cout << "YES" << endl;
        int sz = s / a;
        int cnt = 0;
        FOR(i, 1, n) {
            if (cnt < sz - 1) {
                cout << a << " ";
            } else {
                cout << b << ' ';
            }
            cnt = (cnt + 1) % sz;
        }
        cout << endl;
        return;
    } else {
        // b是a的倍数
        // 倍数为2，判断长度是否过长
        if (b == a * 2) {
            int sz = s / a;
            if (n >= sz) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
                FOR(i, 1, n) cout << a << " ";
                cout << endl;
            }
        } else {
            // 构造循环块
            cout << "YES" << endl;
            int sz = s / b;
            int cnt = 0;
            FOR(i, 1, n) {
                if (cnt < sz - 1) {
                    cout << b << " ";
                } else {
                    cout << a << ' ';
                }
                cnt = (cnt + 1) % sz;
            }
            cout << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}