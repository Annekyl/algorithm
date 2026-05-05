#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while (n--) {
        int m, d, c;
        cin >> m >> d >> c;
        // 可以享受早鸟价
        if (m < 6 || (m == 6 && d <= 20)) {
            if (c < 1800) {
                cout << "Need more!" << endl;
            } else if (c == 1800) {
                cout << "Ok!" << endl;
            } else {
                cout << "^_^" << endl;
            }
        } else if (m > 7 || m == 7 && d > 11) {
            cout << "Too late!" << endl;
        } else {
            if (c < 2000) {
                cout << "Need more!" << endl;
            } else if (c == 2000) {
                cout << "Ok!" << endl;
            } else {
                cout << "^_^" << endl;
            }
        }
    }

    return 0;
}