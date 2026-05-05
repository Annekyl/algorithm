#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e5 + 10;
const int mod = 99991;

int n;
int snow[N][6], head[N], ne[N], tot;

// 哈希函数
int h(int *a) {
    int sum = 0, mul = 1;
    for (int i = 0; i < 6; i++) {
        sum = (sum + a[i]) % mod;
        mul = ((ll)mul * a[i]) % mod;
    }
    return (sum + mul) % mod;
}

bool equal(int *a, int *b) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            // 顺时针是否相同
            bool eq = 1;
            for (int k = 0; k < 6; k++) {
                if (a[(i + k) % 6] != b[(j + k) % 6]) {
                    eq = 0;
                    break;
                }
            }
            if (eq)
                return 1;
            // 逆时针是否相同
            eq = 1;
            for (int k = 0; k < 6; k++) {
                if (a[(i + k) % 6] != b[(j - k + 6) % 6]) {
                    eq = 0;
                    break;
                }
            }
            if (eq)
                return 1;
        }
    }
    return 0;
}

// 判断是否相同，插入雪花
bool insert(int *a) {
    int val = h(a);

    // 遍历哈希得到的链表
    for (int i = head[val]; i; i = ne[i]) {
        if (equal(snow[i], a))
            return 1;
    }

    // 没有找到相同的雪花，插入当前雪花
    memcpy(snow[++tot], a, sizeof(int) * 6);
    ne[tot] = head[val];
    head[val] = tot;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a[6];
        for (int j = 0; j < 6; j++) {
            cin >> a[j];
        }
        if (insert(a)) {
            cout << "Twin snowflakes found.";
            return 0;
        }
    }
    cout << "No two snowflakes are alike.";
    return 0;
}