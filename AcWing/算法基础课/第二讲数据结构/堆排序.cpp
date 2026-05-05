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

int n, m;
int a[N];

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

void down(int p) {
    int s = p * 2; // 存左右子节点中较小的节点
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

int get_min() { return heap[1]; }

void remove_min() {
    heap[1] = heap[tot--];
    down(1);
}

void insert(int val) {
    heap[++tot] = val;
    up(tot);
}

void solve() {
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) insert(a[i]);

    FOR(i, 1, m) {
        cout << get_min() << " ";
        remove_min();
    }
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