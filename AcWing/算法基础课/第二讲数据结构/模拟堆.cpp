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
int heap[N], tot;
int ph[N], hp[N];

void heap_swap(int a, int b) {
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(heap[a], heap[b]);
}

void up(int p) {
    while (p > 1) {
        if (heap[p] < heap[p / 2]) {
            heap_swap(p, p / 2);
            p /= 2;
        } else {
            break;
        }
    }
}

void down(int p) {
    int child = p * 2;
    while (child <= tot) {
        if (child + 1 <= tot && heap[child] > heap[child + 1])
            child++;
        if (heap[child] < heap[p]) {
            heap_swap(child, p);
            p = child;
            child = p * 2;
        } else {
            break;
        }
    }
}

void insert(int m, int val) {
    ph[m] = ++tot;
    hp[tot] = m;
    heap[tot] = val;
    up(tot);
}

void remove_min() {
    heap_swap(1, tot);
    tot--;
    down(1);
}

int get_min() { return heap[1]; }

void solve() {
    cin >> n;
    // FOR(i, 1, n) cin >> a[i];

    int m = 0; // 当前插入了几个数字
    while (n--) {
        string s;
        cin >> s;
        if (s == "I") {
            int x;
            cin >> x;
            ++m;
            insert(m, x);
        } else if (s == "PM") {
            cout << get_min() << endl;
        } else if (s == "DM") {
            remove_min();
        } else if (s == "D") {
            int k;
            cin >> k;
            int pos = ph[k];
            heap_swap(pos, tot);
            tot--;
            if (pos <= tot) {
                up(pos);
                down(pos);
            }
        } else {
            int k, x;
            cin >> k >> x;
            int pos = ph[k];
            heap[pos] = x;
            up(pos);
            down(pos);
        }
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