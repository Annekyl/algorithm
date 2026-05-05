#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e5 + 10;

// 0：6个
// 1：2个
// 2：5个
// 4：4个
// 7：3个
// 8：7个
// 2个选1 3个选7 4个选4 5个选2 6个选0 7个选8
// 8个选20
// 9个选18
// 10个选22或17个选200
// 11个选20
// 12个选28
// 13个选80
int need[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int n;

void solve() {
    cin >> n;
    int k = n / 7, r = n % 7;
    if (r == 0) {
        for (int i = 1; i <= k; i++)
            cout << 8;
    } else if (r == 1) {
        if (k >= 1) {
            cout << 10;
            for (int i = 1; i <= k - 1; i++)
                cout << 8;
        } else
            cout << -1;
    } else if (r == 2) {
        cout << 1;
        for (int i = 1; i <= k; i++)
            cout << 8;
    } else if (r == 3) {
        if (k >= 2) {
            cout << 200;
            for (int i = 1; i <= k - 2; i++)
                cout << 8;
        } else if (k == 1)
            cout << 22;
        else
            cout << 7;
    } else if (r == 4) {
        if (k >= 1) {
            cout << 20;
            for (int i = 1; i <= k - 1; i++)
                cout << 8;
        } else
            cout << 4;
    } else if (r == 5) {
        if (k >= 1) {
            cout << 2;
            for (int i = 1; i <= k; i++)
                cout << 8;
        } else {
            cout << 2;
        }
    } else if (r == 6) {
        cout << 6;
        for (int i = 1; i <= k; i++) {
            cout << 8;
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}