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
constexpr int N = 510;
constexpr int M = 1e5 + 10;

int n1, n2, m;
int match[N];
bool v[N];

int ver[M], head[N], ne[M], tot;

void add(int x, int y) {
    ver[++tot] = y;
    ne[tot] = head[x], head[x] = tot;
}

bool find(int x) {
    for (int i = head[x]; i; i = ne[i]) {
        int y = ver[i];
        if (v[y])
            continue;
        v[y] = 1;
        if (match[y] == 0 || find(match[y])) {
            match[y] = x;
            return true;
        }
    }

    return false;
}

void solve() {
    cin >> n1 >> n2 >> m;
    FOR(i, 1, m) {
        int x, y;
        cin >> x >> y;
        add(x, y);
    }

    int ans = 0;
    FOR(i, 1, n1) {
        memset(v, 0, sizeof v);
        if (find(i)) {
            ans++;
        }
    }
    cout << ans;
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