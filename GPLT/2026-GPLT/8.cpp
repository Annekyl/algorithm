#include "bits/stdc++.h"
#define int long long
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

string s;

void solve1() {
    string s1;
    cin >> s1;
    int cnt = 0;
    vector<int> res;
    int pos = 0;
    while (s.find(s1, pos) != string::npos) {
        pos = s.find(s1, pos);
        res.push_back(pos);
        if (++cnt == 3)
            break;
        pos++;
    }
    if (cnt == 0)
        cout << -1 << endl;
    else {
        for (int i = 0; i < cnt; i++) {
            if (i)
                cout << " ";
            cout << res[i];
        }
        cout << endl;
    }
}
void solve2() {
    int p;
    string s2;
    cin >> p >> s2;
    s.insert(p, s2);
    cout << s << endl;
}
void solve3() {
    int l, r;
    cin >> l >> r;
    reverse(s.begin() + l, s.begin() + r + 1);
    cout << s << endl;
}

signed main() {
    int n;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;
        if (op == 1)
            solve1();
        else if (op == 2)
            solve2();
        else
            solve3();
    }

    return 0;
}
