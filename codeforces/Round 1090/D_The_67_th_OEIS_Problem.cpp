#include "bits/stdc++.h"
#define int long long
#define endl '\n'

#define debug(x) cout << #x << " = " << x << '\n'

using namespace std;

typedef pair<int, int> pii;

const int N = 2e5 + 10;	// ⚠️N要开的足够大，保证能够筛选出 1e4 + 1 个素数

int primes[N];
int cnt = 0;
bool st[N];

// 线性筛法
void get_primes() {
    for (int i = 2; i < N; i++) {
        if (!st[i])
            primes[cnt++] = i;

        for (int j = 0; primes[j] <= N / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << primes[i] * primes[i + 1] << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    get_primes();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
