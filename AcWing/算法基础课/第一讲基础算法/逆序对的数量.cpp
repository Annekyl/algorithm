#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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
int temp[N];

int merge_sort(int l, int r) {
    if (l >= r)
        return 0;
    int mid = (l + r) >> 1;
    int ret = merge_sort(l, mid) + merge_sort(mid + 1, r);

    int cnt = 0;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j])
            temp[cnt++] = a[i++];
        else
            temp[cnt++] = a[j++], ret += mid - i + 1;
    }
    while (i <= mid)
        temp[cnt++] = a[i++];
    while (j <= r)
        temp[cnt++] = a[j++];

    FOR(k, 0, cnt - 1) a[l + k] = temp[k];
    return ret;
}

void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    int ans = merge_sort(1, n);
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