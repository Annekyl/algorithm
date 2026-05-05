#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int MAX_N = 1e5 + 10;

int n, m;
vector<int> ans;

void solve(int x) {
    // 剪枝
    if (ans.size() > m || ans.size() + (n - x + 1) < m) {
        return;
    }

    if (ans.size() == m) {
        for (auto &num : ans) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }
    if (x == n + 1) {
        return;
    }
    ans.push_back(x);
    solve(x + 1);
    ans.pop_back();
    solve(x + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    solve(1);

    return 0;
}