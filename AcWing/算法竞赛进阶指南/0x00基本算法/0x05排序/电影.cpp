#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 2e5 + 10;

int n, m;
map<int, int> a;
int b[N], c[N];
struct node {
    int idx;
    int c1, c2;
} movie[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        movie[i].idx = i;
        movie[i].c1 = a[b[i]];
    }
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
        movie[i].c2 = a[c[i]];
    }

    sort(movie + 1, movie + m + 1, [](node &a, node &b) {
        return a.c1 != b.c1 ? a.c1 > b.c1 : a.c2 > b.c2;
    });
    
    cout << movie[1].idx << endl;
    return 0;
}