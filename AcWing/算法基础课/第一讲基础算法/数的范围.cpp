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

int n, q;
int a[N];

bool check(int idx, int x) { return a[idx] <= x; }

void solve() {
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    while (q--) {
        int x, st = -1, ed = -1;
        cin >> x;

        // 找第一个位置
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (a[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (a[l] != x) {
            cout << "-1 -1" << endl;
            continue;
        } else {
            st = l;
        }

        // 找最后一个位置
        l = 1, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid, x)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (a[l] != x) {
            cout << "-1 -1" << endl;
            continue;
        } else {
            ed = l;
        }

        cout << st - 1 << " " << ed - 1 << endl;
    }
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