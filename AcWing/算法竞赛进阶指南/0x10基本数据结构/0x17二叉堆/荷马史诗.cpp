#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e5 + 10;

int n, k;
ll w[N];
priority_queue<pair<ll, ll>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        q.push(make_pair(-w[i], 0));
    }

    while ((n - 1) % (k - 1) != 0) {
        q.push(make_pair(0, 0));
        n++;
    }
    ll ans = 0;
    while (q.size() > 1) {
        ll num = 0;
        ll depth = 0;
        for (int i = 1; i <= k; i++) {
            num += q.top().first;
            depth = min(depth, q.top().second);
            q.pop();
        }
        q.push(make_pair(num, depth - 1));
        ans -= num;
    }
    cout << ans << endl;
    cout << -q.top().second;
    return 0;
}