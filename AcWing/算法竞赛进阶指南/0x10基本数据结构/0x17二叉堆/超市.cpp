#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e5 + 10;

int n;
pii a[N]; // 商品 first过期时间 second利润

int heap[N], tot;

void up(int p) {
    while (p > 1) {
        if (heap[p] < heap[p / 2]) {
            swap(heap[p], heap[p / 2]);
            p /= 2;
        } else {
            break;
        }
    }
}

void push(int x) {
    heap[++tot] = x;
    up(tot);
}

void down(int p) {
    int s = p * 2; // 左节点
    while (s <= tot) {
        if (s < tot && heap[s] > heap[s + 1])
            s++;
        if (heap[s] < heap[p]) {
            swap(heap[s], heap[p]);
            p = s;
            s = p * 2;
        } else {
            break;
        }
    }
}

void pop() {
    heap[1] = heap[tot--];
    down(1);
}

int top() { return heap[1]; }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n) {
        tot = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].second >> a[i].first;
        }
        sort(a + 1, a + n + 1);

        for (int i = 1; i <= n; i++) {
            int day = a[i].first, val = a[i].second;
            if (day > tot) {
                push(val);
            } else if (day == tot) {
                if (val > top()) {
                    pop();
                    push(val);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= tot; i++) {
            ans += heap[i];
        }
        cout << ans << endl;
    }

    return 0;
}