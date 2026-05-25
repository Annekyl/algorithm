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

    bool check(int mid, int d) {
        int val = (1 + mid) * mid / 2;
        return val <= d;
    }

    void solve() {
        int n, k;
        cin >> n >> k;
        string s;
        string ans = "ab";
        int d = k - (n - 1);
        // debug(d);
        vi lens;
        while (d) {
            int l = 1, r = d;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (check(mid, d)) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            lens.push_back(l);
            int val = (1 + l) * l / 2;
            d -= val;
        }

        for (int i = 0; i < lens.size(); i++) {
            if (i > 0) {
                int x = (int)(ans[ans.size() - 2] - 'a');
                int y = (int)(ans[ans.size() - 1] - 'a');
                for (int i = 0; i < 3; i++) {
                    if (i != x && i != y)
                        ans.push_back('a' + i);
                }
            }
            int len = lens[i];
            while (len--) {
                char c = ans[ans.size() - 2];
                ans += c;
            }
        }

        while (ans.size() < n) {
            int x = (int)(ans[ans.size() - 1] - 'a');
            int y = (int)(ans[ans.size() - 2] - 'a');
            for (int i = 0; i < 3; i++) {
                if (i != x && i != y)
                    ans.push_back('a' + i);
            }
        }

        cout << ans << endl;
    }

    signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int t = 1;
        cin >> t;
        while (t--) {
            solve();
        }

        return 0;
    }
