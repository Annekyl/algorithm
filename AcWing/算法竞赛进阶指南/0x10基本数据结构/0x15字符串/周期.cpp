#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e6 + 10;

int n;
char s[N];
int ne[N];

void calc_next() {
    ne[1] = 0;
    int n = strlen(s + 1);
    for (int i = 2, j = 0; i <= n; i++) {
        while (j > 0 && s[i] != s[j + 1])
            j = ne[j];
        if (s[i] == s[j + 1])
            j++;
        ne[i] = j;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 0;
    while (cin >> n, n) {
        ++cnt;
        cin >> s + 1;
        calc_next();
        cout << "Test case #" << cnt << endl;
        for (int i = 2; i <= n; i++) {
            if (i % (i - ne[i]) == 0 && i / (i - ne[i]) > 1) {
                cout << i << " " << i / (i - ne[i]) << endl;
            }
        }
        cout << endl;
    }

    return 0;
}