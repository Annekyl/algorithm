#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 2010;

int n, m;
int a[N];
int b[N];
int f[N];

void calc() {
    priority_queue<pair<int, pii>> q;
    q.push(make_pair(-a[1] - b[1], make_pair(1, 1)));

    for (int i = 1; i <= n; i++) {
        f[i] = -q.top().first;
        int x = q.top().second.first, y = q.top().second.second;
        q.pop();

        if (y == 1) {
            q.push(make_pair(-a[x + 1] - b[y], make_pair(x + 1, y)));
        }
        q.push(make_pair(-a[x] - b[y + 1], make_pair(x, y + 1)));
    }
}

void solve() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    m--;
    while (m--) {
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        sort(b + 1, b + n + 1);
        calc();
        memcpy(a, f, sizeof a);
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}