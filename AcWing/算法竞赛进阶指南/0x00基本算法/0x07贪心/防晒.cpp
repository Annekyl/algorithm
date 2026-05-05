#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e5 + 10;

int c, l;
vector<pii> cows;
vector<pii> sun;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> l;
    for (int i = 1; i <= c; i++) {
        int x, y;
        cin >> x >> y;
        cows.push_back(make_pair(x, y));
    }
    for (int i = 1; i <= l; i++) {
        int x, y;
        cin >> x >> y;
        sun.push_back(make_pair(x, y));
    }

    sort(cows.begin(), cows.end());
    sort(sun.begin(), sun.end());

    int ans = 0;
    int cow = 0;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (auto &s : sun) {
        int spf = s.first;
        int cnt = s.second;

        // 如果当前奶牛的minSPF小于等于当前防晒霜的SPF，则加入堆中
        while (cow < c && cows[cow].first <= spf) {
            min_heap.push(cows[cow].second);
            cow++;
        }

        while (min_heap.size() && cnt > 0) {
            int max_spf = min_heap.top();
            min_heap.pop();

            if (max_spf >= spf) {
                ans++;
                cnt--;
            }
        }
    }
    
    cout << ans;
    return 0;
}