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

int n, k;
int a[N];

void quick_sort(int l, int r) {
    if (l >= r) {
        return;
    }
    int i = l - 1, j = r + 1, x = a[(l + r) >> 1];
    while (i < j) {
        do
            i++;
        while (a[i] < x);
        do
            j--;
        while (a[j] > x);
        if (i < j)
            swap(a[i], a[j]);
    }
    quick_sort(l, j);
    quick_sort(j + 1, r);
}

void solve() {
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    quick_sort(1, n);

    cout << a[k];
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