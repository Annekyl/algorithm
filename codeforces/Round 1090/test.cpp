#include <bits/stdc++.h>
using namespace std;

const int MAXV = 200000; // 足够筛出前 10001 个质数
vector<int> primes;
bool is_composite[MAXV + 1];

void sieve() {
    for (int i = 2; i <= MAXV; ++i) {
        if (!is_composite[i]) primes.push_back(i);
        for (size_t j = 0; j < primes.size() && i * primes[j] <= MAXV; ++j) {
            is_composite[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        // primes 中至少有 n+1 个元素（n <= 1e4）
        for (int i = 0; i < n; ++i) {
            long long val = 1LL * primes[i] * primes[i + 1];
            cout << val << (i + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
}