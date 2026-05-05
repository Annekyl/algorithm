#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e5 + 10;

struct Cow {
    int idx, st, ed;
    bool operator<(const Cow &c2) { return st < c2.st; }
} cows[N];

int n;
vector<int> ans(N); // 存答案，每头牛被存到的畜栏

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cows[i].st >> cows[i].ed;
        cows[i].idx = i;
    }
    sort(cows + 1, cows + n + 1);

    priority_queue<pii, vector<pii>, greater<pii>> pq; // 存结束时间的畜栏编号
    int cnt = 0;                                       // 当前的畜栏数量

    for (int i = 1; i <= n; i++) {
        Cow cow = cows[i];
        if (pq.empty() || pq.top().first >= cow.st) {
            pq.push(make_pair(cow.ed, ++cnt));
            ans[cow.idx] = cnt;
            // cout << cnt << endl;
        } else {
            int num = pq.top().second;
            pq.pop();
            pq.push(make_pair(cow.ed, num));
            ans[cow.idx] = num;
        }
    }

    cout << cnt << endl;
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}