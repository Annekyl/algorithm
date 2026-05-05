#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e5 + 10;

int idx;
int n;

void solve() {
    cin >> idx >> n;
    cout << idx << " ";
    cout << (n + 1) / 2 << endl;

    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int cnt = 0;
    int x;
    cin >> x;
    max_heap.push(x);
    cnt++;
    cout << max_heap.top() << " ";

    for (int i = 1; i < n; i++) {
        cin >> x;
        // 入堆
        if (x > max_heap.top()) {
            min_heap.push(x);
        } else {
            max_heap.push(x);
        }

        // 调整堆的大小
        if (min_heap.size() > max_heap.size()) {
            int num = min_heap.top();
            min_heap.pop();
            max_heap.push(num);
        } else if (max_heap.size() > min_heap.size() + 1) {
            int num = max_heap.top();
            max_heap.pop();
            min_heap.push(num);
        }
        if (++cnt % 2 == 1) {
            cout << max_heap.top() << " ";
        }
        if (cnt % 20 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}