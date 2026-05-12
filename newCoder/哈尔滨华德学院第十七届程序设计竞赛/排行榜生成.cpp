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
const int N = 1e5 + 10;

struct Node {
    string id;
    int cnt, sum;
    bool operator<(const Node &other) const {
        if (cnt != other.cnt)
            return cnt > other.cnt;
        else if (sum != other.sum)
            return sum < other.sum;
        else
            return id < other.id;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Node> a;
    for (int i = 0; i < n; i++) {
        string id;
        cin >> id;
        int cnt = 0, sum = 0;
        for (int _ = 0; _ < m; _++) {
            int x;
            cin >> x;
            if (x != 0) {
                cnt++;
                sum += x;
            }
        }
        a.push_back({id, cnt, sum});
    }
    sort(a.begin(), a.end());
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i].cnt == a[i - 1].cnt && a[i].sum == a[i - 1].sum) {

        } else {
            pos = i + 1;
        }
        auto [id, cnt, sum] = a[i];
        cout << pos << " " << id << " " << cnt << " " << sum << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
