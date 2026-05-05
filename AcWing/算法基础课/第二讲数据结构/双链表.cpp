#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

int n;

int head, tail, v[N], ne[N], pre[N], tot;

void insert(int x, int idx) {
    v[++tot] = x;
    ne[tot] = ne[idx], pre[tot] = idx;
    ne[idx] = tot, pre[ne[tot]] = tot;
}

void del(int idx) {
    ne[pre[idx]] = ne[idx];
    pre[ne[idx]] = pre[idx];
}

void solve() {
    cin >> n;
    ne[0] = 1, pre[1] = 0;
    tot = 1;
    while (n--) {
        string c;
        cin >> c;
        if (c == "L") {
            int x;
            cin >> x;
            insert(x, 0);
        } else if (c == "R") {
            int x;
            cin >> x;
            insert(x, pre[1]);
        } else if (c == "D") {
            int k;
            cin >> k;
            del(k + 1);
        } else if (c == "IL") {
            int k, x;
            cin >> k >> x;
            insert(x, pre[k + 1]);
        } else if (c == "IR") {
            int k, x;
            cin >> k >> x;
            insert(x, k + 1);
        }
    }
    for (int i = ne[0]; i != 1; i = ne[i]) {
        cout << v[i] << " ";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}