//
// Created by 30694 on 2025/5/25.
//
#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 10;

int l[N], r[N], idx;


int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin() + 1, a.end());

    vector<pair<int, int>> ans(n + 1);
    auto pre = a[1];
    for (int i = 2; i < n; ++i) {
        auto next = a[i + 1];

        int pre_sub = abs(a[i].first - pre.first);
        int next_sub = abs(a[i].first - next.first);
        if (pre_sub <= next_sub) {
            ans[a[i].second] = {pre_sub, pre.second};
        } else {
            ans[a[i].second] = {next_sub, next.second};
        }
    }

    ans[a[n].second] = {abs(a[n].first - a[n - 1].second), a[n - 1].second};

    for (int i = 2; i <= n; ++i) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}