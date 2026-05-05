#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1010;

int n;
vector<pii> arr;

// 高精度乘法
vector<int> mul(vector<int> &a, int b) {
    // 将数先倒过来
    reverse(a.begin(), a.end());

    vector<int> c; // 数组
    int t = 0;     // 当前还没有处理的数
    // 倒着存
    for (int i = 0; i < a.size() || t; i++) {
        if (i < a.size())
            t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    reverse(c.begin(), c.end());
    return c;
}

// 高精度除法
vector<int> div(vector<int> &a, int b) {
    vector<int> c;
    int r = 0; // 余数

    // 正着存
    for (int i = 0; i < a.size(); i++) {
        r = r * 10 + a[i];
        c.push_back(r / b);
        r %= b;
    }

    // 倒过来，去掉前导零后再倒回去
    reverse(c.begin(), c.end());
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();
    reverse(c.begin(), c.end());
    return c;
}

vector<int> max_val(vector<int> &a, vector<int> &b) {
    if (a.size() != b.size()) {
        return a.size() > b.size() ? a : b;
    } else {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                return a[i] > b[i] ? a : b;
            }
        }
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }

    // 国王始终站在第一位
    sort(arr.begin() + 1, arr.end(), [](pii &a, pii &b) {
        return a.first * a.second < b.first * b.second;
    });

    vector<int> ans;
    vector<int> s; // 左手的和
    s.push_back(arr[0].first);
    for (int i = 1; i <= n; i++) {
        auto sum = div(s, arr[i].second);
        ans = max_val(ans, sum);
        s = mul(s, arr[i].first);
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    return 0;
}