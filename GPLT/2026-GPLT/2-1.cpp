#include "bits/stdc++.h"
#define int long long
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

typedef pair<int, int> pii;

signed main() {
    int n, t;
    cin >> n >> t;
    vector<pii> stk;
    bool first = true;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x <= t) {
            if (!first)
                cout << " ";
            cout << i;
            first = false;
        } else {
            stk.push_back({i, x});
        }
    }
    while (stk.size()) {
        vector<pii> temp;
        int sum = 0, avg = 0;
        for (int i = 0; i < stk.size(); i++) {
            sum += stk[i].second;
        }
        avg = sum / stk.size();
        for (int i = stk.size() - 1; i >= 0; i--) {
            int id = stk[i].first;
            int x = stk[i].second;
            if (x <= avg) {
                if (!first)
                    cout << " ";
                cout << id;
                first = false;
            } else {
                temp.push_back({id, x});
            }
        }
        stk = temp;
    }
    return 0;
}
