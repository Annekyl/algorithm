#include "bits/stdc++.h"

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());

    vector<bool> f(m + 1, false);
    bool path[n + 1][m + 1];
    memset(path, 0, sizeof path);
    f[0] = true;
    for (int i = 1; i <= n; i++) {
        int x = a[i - 1];
        for (int j = m; j >= x; j--) {
            if (f[j - x]) {
                f[j] = true;
                path[i][j] = true;
            }
        }
    }

    if (!f[m])
        cout << "No Solution" << endl;
    else {
        vector<int> res;
        int cur = m;
        for (int i = n; i > 0; i--) {
            if (path[i][cur]) {
                res.push_back(a[i - 1]);
                cur -= a[i - 1];
            }
        }

        for (int i = 0; i < res.size(); i++) {
            if (i)
                cout << " ";
            cout << res[i];
        }
    }
    return 0;
}