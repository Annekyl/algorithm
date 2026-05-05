//
// Created by Annekyl on 25-7-7.
//
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

ll a, b, p;

ll mul() {
    ll ans = 0;
    for (; b; b >>= 1) {
        if (b & 1)ans = (ans + a) % p;
        a = a * 2 % p;
    }
    return ans;
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    cin >> a >> b >> p;
    cout << mul();
    return 0;
}
