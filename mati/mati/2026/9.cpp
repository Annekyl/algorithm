#include "bits/stdc++.h"
#define int long long

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
const int N = 3e5 + 10;

vi prime;
bool not_prime[N];

void get_prime() {
    for (int i = 2; i < N; i++) {
        if (!not_prime[i])
            prime.push_back(i);
        for (int j = 0; prime[j] < N / i; j++) {
            not_prime[prime[j] * i] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vi a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    get_prime();

    cout << prime.size() << endl;
    // for (int x : prime)
    //     cout << x << ' ';
    // cout << endl;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}