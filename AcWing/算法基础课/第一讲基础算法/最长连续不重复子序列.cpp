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

int n;
int a[N];
map<int, int> mp;

void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    int i = 1, j = 1;
    int ans = 0;
    while (j <= n) {
        if (mp[a[j]] == 0) {
            mp[a[j]]++;
        } else {
            // cout << "i:" << i << endl;
            // cout << "j:" << j << endl;

            // 先更新当前的长度
            ans = max(ans, j - i);

            // 移动到重复元素的位置
            while (a[i] != a[j]) {
                mp[a[i]]--;
                i++;
            }

            // cout << "i:" << i << endl;
            // cout << "j:" << j << endl;
            // i指针前移一位
            i++;
        }
        j++;
    }
    // cout << "i:" << i << endl;
    // cout << "j:" << j << endl;
    ans = max(ans, j - i);
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}