#include "bits/stdc++.h"

#define int long long
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    deque<pii> q;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (q.empty()) {
            ans++;
            q.push_back({i, a[i]});
        } else {
            while (q.size()) {
                auto [l, g] = q.front();
                if (a[i] % g == 0) {
                    // 不需要更新队头
                    ans += i - l + 1;
                    // 需要更新队尾
                    if (q.size() == 1) {
                        q.push_back({i, a[i]});
                    } else {
                        while (q.size() > 1) {
                            auto [l2, g2] = q.back();
                            if (a[i] % g2 == 0) {
                                // TODO: 插入
                                q.push_back({i, a[i]});
                            } else if (g2 % a[i] == 0) {
                                q.pop_back();
                                q.push_back({l2, a[i]});
                                break;
                            } else {
                                q.pop_back();
                                if (q.size() == 1) {
                                    q.push_back({i, a[i]});
                                    break;
                                }
                            }
                        }
                    }
                    break;
                } else if (g % a[i] == 0) {
                    // 需要更新队头
                    q.pop_front();
                    q.push_front({l, a[i]});
                    ans += i - l + 1;
                    break;
                } else {
                    q.pop_front();
                    if (q.empty()) {
                        ans++;
                        q.push_back({i, a[i]});
                        break;
                    }
                }
            }
        }
        // cout << i << ' ' << ans << " " << q.front().first << " "
            //  << q.front().second << endl;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}