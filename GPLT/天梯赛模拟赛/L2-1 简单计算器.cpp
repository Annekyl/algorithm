#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

signed main() {
    int n;
    cin >> n;
    stack<int> a;
    stack<char> ops;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push(x);
    }
    for (int i = 1; i < n; i++) {
        char c;
        cin >> c;
        ops.push(c);
    }
    while (ops.size()) {
        char op = ops.top();
        ops.pop();
        int n1 = a.top();
        a.pop();
        int n2 = a.top();
        a.pop();
        if (op == '+') {
            a.push(n2 + n1);
        } else if (op == '-') {
            a.push(n2 - n1);
        } else if (op == '*') {
            a.push(n2 * n1);
        } else {
            if (n1 != 0)
                a.push(n2 / n1);
            else {
                cout << "ERROR: " << n2 << "/0" << endl;
                return 0;
            }
        }
    }
    cout << a.top() << endl;
    return 0;
}