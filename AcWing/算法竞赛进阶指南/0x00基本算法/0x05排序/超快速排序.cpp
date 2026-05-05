#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 5e5 + 10;

int n;
int a[N];
int b[N]; // 辅助数组
ll ans;  // 记录逆序对个数

void merge_cnt(int l, int r, int mid) {
    // 双指针
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
        if (j > r || i <= mid && a[i] <= a[j]) {
            b[k] = a[i++];
        } else {
            b[k] = a[j++];
            ans += mid - i + 1;
        }
    }
    for (int k = l; k <= r; k++) {
        a[k] = b[k];
    }
}

void merge_sort(int l, int r) {
    if (l < r) {
        int mid = (l + r) >> 1;
        merge_sort(l, mid);
        merge_sort(mid + 1, r);
        merge_cnt(l, r, mid);
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ans = 0;
    merge_sort(1, n);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n) {
        if (n == 0)
            break;
        solve();
    }

    return 0;
}