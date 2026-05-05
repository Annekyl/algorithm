#include "bits/stdc++.h"

#define int long long
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

int n;
string st;
unordered_map<string, int> d;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool valid(int x, int y) { return x >= 0 && x < 3 && y >= 0 && y < 3; }

void solve() {
    FOR(i, 1, 9) {
        char c;
        cin >> c;
        st += c;
    }

    queue<string> q;
    q.push(st);
    d[st] = 0;
    while (q.size()) {
        auto t = q.front();
        q.pop();

        int dis = d[t];
        int idx = t.find('x');
        int x = idx / 3, y = idx % 3;
        FOR(i, 0, 3) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny)) {
                swap(t[nx * 3 + ny], t[idx]);
                if (d.find(t) == d.end()) {
                    d[t] = dis + 1;
                    q.push(t);
                }
                swap(t[nx * 3 + ny], t[idx]);
            }
        }
    }

    string ed = "12345678x";
    if (d.find(ed) == d.end()) {
        cout << -1;
    } else {
        cout << d[ed];
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