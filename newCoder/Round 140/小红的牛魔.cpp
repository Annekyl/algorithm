#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'
#define forr(i, l, r) for (int i = (l); i <= (r); ++i)
#define ref(i, l, r) for (int i = (l); i >= (r); --i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 10;

int n, m;

void solve() {
    cin >> n;
    // string s;
    // cin >> s;
    // while (1) {
    //     int sz = 3;
    //     auto pos = s.find("niu");
    //     if (pos == string::npos) {
    //         pos = s.find("mo");
    //         sz = 2;
    //     }
    //     if (pos == string::npos)
    //         break;
    //     s.erase(pos, sz);
    // }
    // // cout << s << endl;
    // if (s.size())
    //     cout << "No";
    // else
    //     cout << "Yes";
    vector<char> a;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        // cout << c << " ";
        a.push_back(c);
        if (a.size() >= 3 && a[a.size() - 3] == 'n' && a[a.size() - 2] == 'i' &&
            a[a.size() - 1] == 'u') {
            a.pop_back();
            a.pop_back();
            a.pop_back();
        }
        if (a.size() >= 2 && a[a.size() - 2] == 'm' && a[a.size() - 1] == 'o') {
            a.pop_back();
            a.pop_back();
        }
    }
    if (a.size() == 0)
        cout << "Yes";
    else
        cout << "No";
}

signed main() {
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
