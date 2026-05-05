#include "bits/stdc++.h"

#define int long long

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

int n, m;
unordered_map<string, char> mp;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        char c;
        cin >> s >> c;
        mp[s] = c;
    }

    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        // cout << "i:" << i << endl;
        // cout << "s:" << s << endl;
        if (mp.find(s) != mp.end()) {
            cout << mp[s] << endl;
            continue;
        }
        vector<string> ans;
        string temp = "";
        for (int i = 1; i < s.size(); i++) {
            string s1 = s.substr(0, i);
            string s2 = s.substr(i);
            if (mp.find(s1) != mp.end() && mp.find(s2) != mp.end()) {
                temp += mp[s1];
                temp += mp[s2];
                ans.push_back(temp);
                temp = "";
            }
        }
        if (ans.size() == 1) {
            cout << ans[0] << endl;
        } else {
            cout << "D" << endl;
        }
    }

    return 0;
}