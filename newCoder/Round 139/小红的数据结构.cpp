#include "bits/stdc++.h"
#define endl '\n'

#define DEBUG

#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << '\n'
#else
#define debug(x)
#endif

using namespace std;

typedef pair<int, int> pii;

const int N = 2e5 + 10;

int n, quary;
int a[N];
stack<int> stk;
queue<int> q;
vector<int> s_a, q_a;

void solve() {
    cin >> n >> quary;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < quary; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            stk.push(x);
            q.push(x);
        } else {
            s_a.push_back(stk.top());
            q_a.push_back(q.front());
            stk.pop();
            q.pop();
        }
    }
    bool suc1 = true, suc2 = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != s_a[i])
            suc1 = false;
        if (a[i] != q_a[i])
            suc2 = false;
    }
    if (suc1 && suc2)
        cout << "both" << endl;
    else if (suc1)
        cout << "stack" << endl;
    else if (suc2)
        cout << "queue" << endl;
    else
        cout << "-1" << endl;
}

int main() {
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
