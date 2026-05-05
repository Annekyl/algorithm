#include "bits/stdc++.h"

#define int long long

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

int n;
int a[2][5];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while (n--) {
        int c, p;
        cin >> c >> p;
        a[c][p]++;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    if (a[0][1] > a[1][1] || a[0][1] == a[1][1] && a[0][2] > a[1][2] ||
        a[0][1] == a[1][1] && a[0][2] == a[1][2] && a[0][3] > a[1][3]) {
        cout << "The first win!";
    } else {
        cout << "The second win!";
    }
    return 0;
}