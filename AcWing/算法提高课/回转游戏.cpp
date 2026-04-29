#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 10;
int a[25];
int path[100];

int line[8][7] = {
    {1, 3, 7, 12, 16, 21, 23},    {2, 4, 9, 13, 18, 22, 24},
    {11, 10, 9, 8, 7, 6, 5},      {20, 19, 18, 17, 16, 15, 14},
    {24, 22, 18, 13, 9, 4, 2},    {23, 21, 16, 12, 7, 3, 1},
    {14, 15, 16, 17, 18, 19, 20}, {5, 6, 7, 8, 9, 10, 11},
};

int opposite[8] = {5, 4, 7, 6, 1, 0, 3, 2};
int center[8] = {7, 8, 9, 12, 13, 16, 17, 18};

int f() {
    int cnt[4] = {0};
    for (int i = 0; i < 8; i++) {
        cnt[a[center[i]]]++;
    }
    int mx = 0;
    for (int i = 1; i <= 3; i++) {
        mx = max(mx, cnt[i]);
    }
    return 8 - mx;
}

void operate(int x) {
    int t = a[line[x][0]];
    for (int i = 0; i < 6; i++) {
        a[line[x][i]] = a[line[x][i + 1]];
    }
    a[line[x][6]] = t;
}

bool dfs(int depth, int max_depth, int last) {
    if (depth + f() > max_depth)
        return false;
    if (f() == 0)
        return true;

    for (int i = 0; i < 8; i++) {
        if (opposite[i] == last)
            continue;
        operate(i);
        path[depth] = i;
        if (dfs(depth + 1, max_depth, i))
            return true;
        operate(opposite[i]);
    }

    return false;
}

void solve() {
    int depth = 0;
    while (!dfs(0, depth, -1))
        depth++;
    if (depth == 0)
        cout << "No moves needed" << endl;
    else {
        for (int i = 0; i < depth; i++)
            cout << (char)(path[i] + 'A');
        cout << endl;
    }
    cout << a[7] << endl;
}

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
