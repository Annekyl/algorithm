#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

string s;

void solve1() {
    string t;
    cin >> t;
    if (s.find(t) != string::npos) {
        cout << s.find(t) << endl;
    } else {
        cout << -1 << endl;
    }
}
void solve2() {
    string s2, s3;
    cin >> s2 >> s3;
    if (s.find(s2) != string::npos) {
        int pos = s.find(s2);
        s.replace(pos, s2.size(), s3);
    }

    cout << s << endl;
}
void solve3() {
    string c1, c2;
    string s4, t;
    cin >> c1 >> c2 >> s4;
    t = c1 + c2;
    // cout << t << " ";
    int pos = 0;
    while (s.find(t, pos) != string::npos) {
        pos = s.find(t, pos);
        s.insert(pos + 1, s4);
        pos += 1 + s4.size();
    }
    cout << s << endl;
}

signed main() {
    int n;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            solve1();
        } else if (op == 2) {
            solve2();
        } else {
            solve3();
        }
    }

    return 0;
}