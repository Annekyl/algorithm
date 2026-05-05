#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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

int n;
int stk[N], tot;

void push(int x) { stk[++tot] = x; }

void pop() { tot--; }

bool empty() { return tot == 0; }

int quary() { return stk[tot]; }

void solve() {
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s == "push") {
            int x;
            cin >> x;
            push(x);
        } else if (s == "pop") {
            pop();
        } else if (s == "empty") {
            if (empty())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        } else {
            cout << quary() << endl;
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