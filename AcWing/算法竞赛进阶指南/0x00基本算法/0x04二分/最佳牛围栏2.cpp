#include "bits/stdc++.h"

using namespace std;

double a[100010];
double b[100010];
double s[100010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, f;

    cin >> n >> f;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    double l = -1e6, r = 1e6;
    double eps = 1e-5;
    while (r - l > eps) {
        double mid = (r + l) / 2;
        for (int i = 1; i <= n; i++) {
            b[i] = a[i] - mid;
        }
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + b[i];
        }
        double ans = -1e10;
        double min_val = 1e10;
        for (int i = f; i <= n; i++) {
            min_val = min(min_val, s[i - f]);
            ans = max(ans, s[i] - min_val);
        }
        if (ans >= 0)
            l = mid;
        else
            r = mid;
    }

    cout << (int)(r * 1000) << endl;
    return 0;
}