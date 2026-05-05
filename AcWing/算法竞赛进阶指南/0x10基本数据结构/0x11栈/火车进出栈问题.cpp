#include "bits/stdc++.h"

#define int long long   

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e5 + 10;

int n;

vector<int> mul(vector<int> &a, int b) {
    vector<int> c;
    reverse(a.begin(), a.end());
    int t = 0;
    for (int i = 0; i < a.size() || t; i++) {
        if (i < a.size())
            t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    reverse(c.begin(), c.end());
    return c;
}

vector<int> div(vector<int> &a, int b) {
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i++) {
        t = t * 10 + a[i];
        c.push_back(t / b);
        t %= b;
    }
    reverse(c.begin(), c.end());
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();
    reverse(c.begin(), c.end());
    return c;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> ans = {n * 2};
    // 计算A(2n,n)
    for (int i = n * 2 - 1; i >= n + 1; i--) {
        ans = mul(ans, i);
    }
    // 计算A(2n,n)/A(n,n),即C(2n,n)
    for (int i = 1; i <= n; i++) {
        ans = div(ans, i);
    }
    // 计算卡特兰数C(2n,n)/(n+1)
    ans = div(ans, n + 1);
    for (auto x : ans) {
        cout << x;
    }
    return 0;
}