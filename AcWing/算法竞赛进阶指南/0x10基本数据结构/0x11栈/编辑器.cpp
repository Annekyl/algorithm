#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e5 + 10;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int s[n + 1]; // 前缀和
    int f[n + 1]; // 当前的最大值

    // 注意初始化数组
    memset(s, 0, sizeof s);
    memset(f, 0xcf, sizeof f); // 最大值可能为负数
    stack<int> min_st;
    stack<int> max_st;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if (c == 'I') {
            int x;
            cin >> x;
            min_st.push(x);
            s[min_st.size()] = s[min_st.size() - 1] + x;
            f[min_st.size()] = max(f[min_st.size() - 1], s[min_st.size()]);
        } else if (c == 'D') {
            if (!min_st.empty()) {
                min_st.pop();
            }
        } else if (c == 'L') {
            if (!min_st.empty()) {
                auto top = min_st.top();
                min_st.pop();
                max_st.push(top);
            }
        } else if (c == 'R') {
            if (!max_st.empty()) {
                auto top = max_st.top();
                max_st.pop();
                min_st.push(top);
                s[min_st.size()] = s[min_st.size() - 1] + top;
                f[min_st.size()] = max(f[min_st.size() - 1], s[min_st.size()]);
            }
        } else if (c == 'Q') {
            int k;
            cin >> k;
            cout << f[k] << endl;
        }
    }

    return 0;
}