#include "bits/stdc++.h"
#define int long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
const int N = 3e5 + 10;

void solve() {
    int n;
    string s;
    cin >> s;
    vi a(n);
    vector<bool> st(n, false); // 当前位置是否被删除
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];
    }
    int i = 0;
    while (i < n) {
        if (a[i] > 0)
            continue;
        // 当前字符的权重为负数，看一下删了是否会使得结果变大
        if (s[i] == 'b' || s[i] == 'c') {
            // 向前找到1
            int j = i - 1;
            int sum = a[i];
            while (1) {
                if(a[j]=='a'&&!st[j]){
                    sum+=a[j];
                    if(sum<=0){
                        // 可以删
                        for(int st)
                    }
                    break;
                }
            }
        } else {
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}