#include "bits/stdc++.h"

#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

string s;
stack<int> nums;
stack<char> ops;
int ans = 0;

int get_priority(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

int calc(int a, int b, char op) {
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/')
        return a / b;
    return 0;
}

void solve() {
    cin >> s;
    int i = 0;
    while (i < s.size()) {
        // 如果是数字
        if (s[i] >= '0' && s[i] <= '9') {
            int num = s[i] - '0';
            while (i + 1 < s.size() && s[i + 1] >= '0' && s[i + 1] <= '9') {
                i++;
                num = num * 10 + (s[i] - '0');
            }
            nums.push(num);
            i++;
        } else if (s[i] == '(') {
            ops.push(s[i]);
            i++;
        } else if (s[i] == ')') {
            while (ops.top() != '(') {
                char c = ops.top();
                ops.pop();
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                nums.push(calc(a, b, c));
            }
            // 弹出左括号
            ops.pop();
            i++;
        } else {
            while (!ops.empty() && ops.top() != '(' &&
                   get_priority(ops.top()) >= get_priority(s[i])) {
                char c = ops.top();
                ops.pop();
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                nums.push(calc(a, b, c));
            }
            ops.push(s[i]);
            i++;
        }
    }

    while (ops.size()) {
        char c = ops.top();
        ops.pop();
        int b = nums.top();
        nums.pop();
        int a = nums.top();
        nums.pop();
        nums.push(calc(a, b, c));
    }
    cout << nums.top();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}