#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 110;

int n, m;
int sum[N]; // 总共出现的次数
int cnt[N]; // 在多少篇文章中出现

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int len;
        cin >> len;
        set<int> rec;
        for (int i = 1; i <= len; i++) {
            int x;
            cin >> x;
            sum[x]++;
            if (rec.find(x) == rec.end()) {
                cnt[x]++;
            }
            rec.insert(x);
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << cnt[i] << " " << sum[i] << endl;
    }
    
    return 0;
}