#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;

int n;
vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int get_num(int st, int ed) {
    int res = 0;
    for (int i = st; i <= ed; i++) {
        res = res * 10 + a[i];
    }
    return res;
}

void solve() {
    cin >> n;
    int ans = 0;
    do {
        for (int i = 1; i <= 7; i++) {
            for (int j = 1; j < 9 - i; j++) {
                int a = get_num(0, i - 1);
                int b = get_num(i, i + j - 1);
                int c = get_num(i + j, 8);
                if (a < n && b % c == 0 && a + b / c == n)
                    ans++;
            }
        }
    } while (next_permutation(a.begin(), a.end()));
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}