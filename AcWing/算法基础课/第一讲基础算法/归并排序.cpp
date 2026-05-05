#include "bits/stdc++.h"

#define int long long
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

int n;
int a[N];

void merge_sort(int l, int r) {
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);

    int cnt = 0, temp[r - l + 1], i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j])
            temp[cnt++] = a[i++];
        else
            temp[cnt++] = a[j++];
    }
    while (i <= mid)
        temp[cnt++] = a[i++];
    while (j <= r)
        temp[cnt++] = a[j++];

    FOR(i, l, r) a[i] = temp[i - l];
}

void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    merge_sort(1, n);
    FOR(i, 1, n) cout << a[i] << " ";
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