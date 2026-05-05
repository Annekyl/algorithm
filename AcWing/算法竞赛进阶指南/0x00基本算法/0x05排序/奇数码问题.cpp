#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 510;

// 注意处理空格0，空格0不参与逆序数的计算
// 注意排完序后，将临时数组的值赋给原数组

int n;
int a[N * N];
int temp[N * N];

ll merge_cnt(int l, int r, int mid) {
    int i = l, j = mid + 1;
    ll ans = 0;
    for (int k = l; k <= r; k++) {
        if (j > r || i <= mid && a[i] <= a[j]) {
            temp[k] = a[i++];
        } else {
            temp[k] = a[j++];
            ans += mid - i + 1;
        }
    }
    for(int k=l;k<=r;k++){
        a[k]=temp[k];
    }

    return ans;
}

ll merge_sort(int l, int r) {
    ll ans = 0;
    if (l < r) {
        int mid = (l + r) >> 1;
        ans += merge_sort(l, mid);
        ans += merge_sort(mid + 1, r);
        ans += merge_cnt(l, r, mid);
    }
    return ans;
}

void solve() {
    int k = 0;
    for (int i = 1; i <= n * n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            continue;
        }
        a[++k] = x;
    }
    int judge1 = merge_sort(1, n * n - 1) % 2;
    k = 0;
    for (int i = 1; i <= n * n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            continue;
        }
        a[++k] = x;
    }
    if (merge_sort(1, n * n - 1) % 2 == judge1) {
        cout << "TAK" << endl;
    } else {
        cout << "NIE" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n) {
        solve();
    }

    return 0;
}