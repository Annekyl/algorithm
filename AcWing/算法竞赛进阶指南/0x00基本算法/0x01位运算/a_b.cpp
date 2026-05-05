//
// Created by Annekyl on 25-7-7.
//
#include "bits/stdc++.h"

using namespace std;

int a, b, p;

int power() {
    int ans = 1 % p;
    for (; b; b >>= 1) {
        if (b & 1)ans = static_cast<long long>(ans) * a % p;
        a = static_cast<long long>(a) * a % p;
    }
    return ans;
}

int main() {
    scanf("%d%d%d", &a, &b, &p);

    int ans = power();
    printf("%d", ans);
    return 0;
}
