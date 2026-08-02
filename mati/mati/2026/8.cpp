#include "bits/stdc++.h"
#define int long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 5e5 + 10;

int n, p[N << 1];
char a[N], s[N << 1];

void change() {
    n = strlen(a);
    int k = 0;
    s[k++] = '$';
    s[k++] = '#';
    for (int i = 0; i < n; i++) {
        s[k++] = a[i];
        s[k++] = '#';
    }
    s[k++] = '&';
    n = k;
}

void manacher() {
    int r = 0, c;
    for (int i = 1; i < n; i++) {
        if (i < r)
            p[i] = min(p[(c << 1) - i], p[c] + c - i);
        else
            p[i] = 1;
        while (s[i + p[i]] == s[i - p[i]])
            p[i]++;
        if (p[i] + i > r) {
            r = p[i] + i;
            c = i;
        }
    }
}

void solve() {
    // cout << 4723 * 0.1 << endl;
    scanf("%s", a);
    string ys = a;
    // cout << ys << endl;
    // int len = strlen(a);
    change();
    manacher();
    for (int i = 0; i < n; i++) {
        cout << p[i] << ' ';
    }
    cout << endl;

    vi cnt(30, 0);
    vi sum(ys.size() + 1, 0);
    for (int i = 2, idx = 0; i < n - 1; i += 2) {
        int len = (p[i] - 1) / 2;
    }
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}