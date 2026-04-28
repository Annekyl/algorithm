#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 20;

int a[N];
int n;
int f() {
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] + 1 != a[i])
            res++;
    }
    return (res + 2) / 3;
}

bool check() {
    for (int i = 1; i < n; i++)
        if (a[i - 1] + 1 != a[i])
            return false;
    return true;
}

bool dfs(int depth, int max_depth) {
    if (depth + f() > max_depth)
        return false;
    if (check())
        return true;
        
    int temp[N];
    memcpy(temp, a, sizeof a);

    for (int len = 1; len <= n; len++) { // 移动的序列长度
        for (int i = 0; i < n; i++) {    // 移动的序列的第一个元素的位置
            for (int j = i + 1; j + len - 1 < n; j++) { // 要移动到的位置
                int l = j, r = j + len - 1;
                for (int k = i; k < j; k++)
                    a[k] = temp[k + len];
                for (int k = l; k <= r; k++) {
                    a[k] = temp[i + k - l];
                }
                if (dfs(depth + 1, max_depth))
                    return true;
                memcpy(a, temp, sizeof a);
            }
        }
    }

    return false;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int depth = 0;
    while (depth < 5 && !dfs(0, depth))
        depth++;
    if (depth >= 5)
        cout << "5 or more" << endl;
    else
        cout << depth << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
