#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e6 + 10;

char s[N];
ull f1[N], f2[N], p[N];

ull h1(int l, int r) { return f1[r] - f1[l - 1] * p[r - l + 1]; }

ull h2(int l, int r) { return f2[l] - f2[r + 1] * p[r - l + 1]; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    p[0] = 1;
    for (int i = 1; i < N; i++) {
        p[i] = p[i - 1] * 131;
    }
    int cnt = 0;
    while (cin >> s + 1, s[1] != 'E' && s[2] != 'N' && s[3] != 'D') {
        int n = strlen(s + 1);
        f2[n + 1] = 0;
        for (int i = 1; i <= n; i++) {
            f1[i] = f1[i - 1] * 131 + (s[i] - 'a' + 1);
        }
        for (int i = n; i > 0; i--) {
            f2[i] = f2[i + 1] * 131 + (s[i] - 'a' + 1);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            // 奇数最长回文串
            int l = 0, r = min(i - 1, n - i);
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (h1(i - mid, i - 1) == h2(i + 1, i + mid)) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            ans = max(ans, l * 2 + 1);
            // 偶数最长回文串
            l = 0, r = min(i - 1, n - i + 1);
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (h1(i - mid, i - 1) == h2(i, i + mid - 1)) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            ans = max(ans, l * 2);
        }
        cout << "Case " << ++cnt << ": " << ans << endl;
    }

    return 0;
}