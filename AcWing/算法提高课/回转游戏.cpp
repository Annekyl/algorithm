#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 10;
int a[25];

int line[8][7] = {
    {1, 3, 7, 12, 16, 21, 23},    {2, 4, 9, 13, 18, 22, 24},
    {11, 10, 9, 8, 7, 6, 5},      {20, 19, 18, 17, 16, 15, 14},
    {24, 22, 18, 13, 9, 4, 2},    {23, 21, 16, 12, 7, 3, 1},
    {14, 15, 16, 17, 18, 19, 20}, {5, 6, 7, 8, 9, 10, 11},
};

int opposite[8] = {5, 4, 7, 6, 1, 0, 3, 2};

void solve() {}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (cin >> a[1], a[1]) {
        for (int i = 2; i <= 24; i++)
            cin >> a[i];
        solve();
    }

    return 0;
}
