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

int ne[N], head, v[N], tot;

void add(int val) {
    v[++tot] = val;
    ne[tot] = head, head = tot;
}

void insert(int val, int idx) {
    v[++tot] = val;
    ne[tot] = ne[idx], ne[idx] = tot;
}

void del(int idx) { ne[idx] = ne[ne[idx]]; }

void del_head() { head = ne[head]; }

void solve() {
    cin >> n;
    while (n--) {
        char c;
        cin >> c;
        if (c == 'H') {
            int x;
            cin >> x;
            add(x);
        } else if (c == 'D') {
            int k;
            cin >> k;
            if (k == 0)
                del_head();
            else
                del(k);
        } else if (c == 'I') {
            int k, x;
            cin >> k >> x;
            insert(x, k);
        }
    }

    for (int i = head; i; i = ne[i]) {
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