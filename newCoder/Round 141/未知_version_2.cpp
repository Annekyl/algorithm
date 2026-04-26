#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define DEBUG

#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << '\n'
#else
#define debug(x)
#endif

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int N = 1e5 + 10;

int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    multiset<int> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    sort(a.begin(), a.end());
    int mx = a[n - 1];
    bool suc = false;
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] == a[i - 1])
            continue;
        int res = a[i];
        int p = 1;
        if (a[i] == 1) {
            if (st.count(1) >= 2) {
                suc = true;
                break;
            }
        } else {
            while (res <= mx) {
                if (st.find(p) != st.end() && st.find(res) != st.end()) {
                    if (p == 1 && st.count(a[i]) >= 2) {
                        suc = true;
                        break;
                    } else if (p == a[i] && st.count(a[i]) >= 2) {
                        suc = true;
                        break;
                    }  else {
                        suc = true;
                        break;
                    }
                }
                p++;
                res *= a[i];
            }
        }
        if (suc)
            break;
    }

    if (suc)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
