#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e6 + 10;

int l, r;
int prime[N];
int v[N];

void primes() {
    memset(v, 0, sizeof v);
    int cnt = 0; // 质数数量
    int n = sqrt(r);
    for (int i = 2; i <= n; i++) {
        if (v[i] == 0) {
            prime[++cnt] = i;
            v[i] = i;
        }
        for (int j = 1; j <= cnt; j++) {
            if (prime[j] > v[i] || prime[j] > n / i)
                break;
            v[i * prime[j]] = prime[j];
        }
    }

    for(int i=l;i<=r;i++){
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> l >> r;
    primes();

    return 0;
}