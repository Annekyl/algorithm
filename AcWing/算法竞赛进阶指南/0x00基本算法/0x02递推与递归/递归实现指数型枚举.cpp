#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int MAX_N = 1e5 + 10;

int n;
vector<int> ans;

void solve(int x) {
    if (x == n + 1) {
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }
    solve(x + 1);
    ans.push_back(x);
    solve(x + 1);
    ans.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    solve(1);

    return 0;
}