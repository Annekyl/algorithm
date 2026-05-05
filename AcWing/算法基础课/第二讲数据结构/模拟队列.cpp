#include "bits/stdc++.h"

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

int q[N], head, tail;

void push(int x) { q[++tail] = x; }

void pop() { head++; }

bool empty() { return head == tail; }

int query() { return q[head + 1]; }

void solve() {
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s == "push") {
            int x;
            cin >> x;
            push(x);
        } else if (s == "pop") {
            pop();
        } else if (s == "empty") {
            if (empty())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        } else {
            cout << query() << endl;
        }
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