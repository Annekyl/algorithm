#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

signed main() {
    int n;
    cin >> n;
    map<string, char> mp;
    for (int i = 0; i < n; i++) {
        string s;
        char c;
        cin >> s >> c;
        mp[s] = c;
    }
    int m;
    cin >> m;
    vector<int> res;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        bool suc = true;
        for (int j = 0; j < k; j++) {
            string s;
            cin >> s;
            if (mp[s] == 'e')
                suc = false;
        }
        if (suc)
            res.push_back(i);
    }
    for (int i = 0; i < res.size(); i++) {
        if (i)
            cout << " ";
        cout << res[i] + 1;
    }
    if (res.size() == 0)
        cout << "None" << endl;

    return 0;
}