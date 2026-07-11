#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)
#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
const int N = 2e5 + 10;

int _case;
int n;

vector<double> ys;

struct Event {
    double x, y1, y2;
    int type;
    bool operator<(Event &other) const { return x < other.x; }
};

struct Node {
    int l, r;
    int cnt;
    double len;
} tr[N * 4];

void pushup(int u) {
    if (tr[u].cnt) {
        tr[u].len = ys[tr[u].r + 1] - ys[tr[u].l];
    } else if (tr[u].l != tr[u].r) {
        tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
    } else {
        tr[u].len = 0;
    }
}

void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l != r) {
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }
}

void modify(int u, int l, int r, int type) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].cnt += type;
        pushup(u);
    } else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)
            modify(u << 1, l, r, type);
        if (r > mid)
            modify(u << 1 | 1, l, r, type);
        pushup(u);
    }
}

void solve() {
    ys.clear();
    vector<Event> events;
    for (int i = 0; i < n; i++) {
        double x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        events.push_back({x1, y1, y2, 1});
        events.push_back({x2, y1, y2, -1});
        ys.push_back(y1);
        ys.push_back(y2);
    }

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    build(1, 0, ys.size() - 1);

    sort(events.begin(), events.end());
    double ans = 0;
    for (int i = 0; i < events.size(); i++) {
        if (i > 0)
            ans += tr[1].len * (events[i].x - events[i - 1].x);
        int y1 = lower_bound(ys.begin(), ys.end(), events[i].y1) - ys.begin();
        int y2 = lower_bound(ys.begin(), ys.end(), events[i].y2) - ys.begin();
        modify(1, y1, y2 - 1, events[i].type);
    }

    cout << "Test case #" << (++_case) << endl;
    cout << "Total explored area: " << fixed << setprecision(2) << ans << endl;
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (cin >> n, n) {
        solve();
    }

    return 0;
}
