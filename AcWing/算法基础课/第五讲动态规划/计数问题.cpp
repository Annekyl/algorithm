#include "bits/stdc++.h"

#define int long long
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

int a, b;

int power10(int n) {
    int ans = 1;
    FOR(i, 1, n) { ans *= 10; }
    return ans;
}

int get(vi &num, int l, int r) {
    int ans = 0;
    REF(i, l, r) { ans = ans * 10 + num[i]; }
    return ans;
}

// 从1到n中数字x出现的次数
int count(int n, int x) {
    if (n <= 0)
        return 0;

    vi num;
    while (n) {
        num.push_back(n % 10);
        n /= 10;
    }

    n = num.size(); // n改为表示位数
    int ans = 0;

    REF(i, n - 1 - !x, 0) {
        // 不是最高位时，计算当前位前面的数字组合
        if (i < n - 1) {
            ans += get(num, n - 1, i + 1) * power10(i);
            if (!x)
                ans -= power10(i);
        }

        if (num[i] == x)
            ans += get(num, i - 1, 0) + 1;
        else if (num[i] > x)
            ans += power10(i);
    }
    return ans;
}

void solve() {
    if (a > b)
        swap(a, b);

    FOR(i, 0, 9) { cout << count(b, i) - count(a - 1, i) << " "; }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;
    while (cin >> a >> b, a && b) {
        solve();
    }
    return 0;
}