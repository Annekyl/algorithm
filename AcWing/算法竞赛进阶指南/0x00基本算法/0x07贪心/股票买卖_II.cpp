#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e5 + 10;

int n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] > a[i - 1]) {
            ans += a[i] - a[i - 1];
        }
    }
    cout << ans;
    return 0;
}