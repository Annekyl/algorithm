#include "bits/stdc++.h"

#define int long long
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

int n;

bool st[100];
map<int, pii> mp;
void init() {
    memset(st, 0, sizeof st);
    vector<int> masks;
    for (int i = 0; i < 512; i++) {
        if (__builtin_popcount(i) <= 6)
            masks.push_back(i);
    }

    for (int mask1 : masks) {
        for (int mask2 : masks) {
            for (int mex = 0; mex < 100; mex++) {
                int d1 = mex / 10, d2 = mex % 10;
                if (d1 == 9)
                    d1 = 6;
                if (d2 == 9)
                    d2 = 6;
                if (((mask1 >> d1) & 1) && ((mask2 >> d2) & 1) ||
                    ((mask2 >> d1) & 1) && ((mask1 >> d2) & 1)) {
                    // 可以拼出
                } else {
                    st[mex] = true;
                    mp[mex] = {mask1, mask2};
                    break;
                }
            }
        }
    }
}

void solve() {
    cin >> n;
    if (!st[n]) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    auto [x, y] = mp[n];
    int first, cnt = 0;
    for (int i = 0; i < 9; i++) {
        if ((x >> i) & 1) {
            cnt++;
            if (cnt == 1)
                first = i;
            cout << i << ' ';
        }
    }
    while (cnt++ < 6)
        cout << first;

    for (int i = 0; i < 9; i++) {
        if ((y >> i) & 1) {
            cnt++;
            if (cnt == 1)
                first = i;
            cout << i << ' ';
        }
    }
    while (cnt++ < 6)
        cout << first;

    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}