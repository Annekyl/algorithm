#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int MAX_N = 1e5 + 10;

int n, f;
int a[MAX_N];
double s[MAX_N]; // 前缀和

bool check(double avg) {
    // 计算前缀和
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i] - avg;
    }

    // 滑动窗口，维护最小值
    double min_v = 0;
    for (int i = f; i <= n; i++) {
        if (s[i] - min_v >= 0) {
            return true;
        }
        min_v = min(min_v, s[i - f + 1]);
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> f;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // 二分答案
    double l = 0, r = 2000;
    while (r - l > 1e-5) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << (int)(r * 1000) << endl;
    return 0;
}