#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int MAX_N = 10;

int n;
vector<int> ans;
vector<bool> v(MAX_N, false);

void solve() {
    if (ans.size() == n) {
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        if (v[i])
            continue;
        ans.push_back(i);
        v[i] = true;
        solve();
        ans.pop_back();
        v[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    solve();

    return 0;
}