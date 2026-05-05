#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 30;

int n;
vector<int> ans;
stack<int> stk;
vector<bool> v(N, false);
int cnt = 0;

void dfs(int x) {
    if (cnt == 20) {
        return;
    }
    if (ans.size() == n) {
        for (auto num : ans) {
            cout << num;
        }
        cout << endl;
        cnt++;
        return;
    }

    // 出栈
    if (!stk.empty()) {
        ans.push_back(stk.top());
        stk.pop();
        dfs(x);
        stk.push(ans.back());
        ans.pop_back();
    }
    // 进栈
    if (x <= n) {
        stk.push(x);
        dfs(x + 1);
        stk.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    dfs(1);

    return 0;
}