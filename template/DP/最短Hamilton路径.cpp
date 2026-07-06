// 最短Hamilton路径 (状压DP)
// AcWing 91. 最短Hamilton路径
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;

int n;
int w[N][N];
int f[1 << N][N]; // f[S][i]: 访问了S集合中的城市，当前在i

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &w[i][j]);

    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;

    for (int s = 1; s < (1 << n); s++) {
        for (int i = 0; i < n; i++) {
            if (!(s >> i & 1)) continue;
            for (int j = 0; j < n; j++) {
                if (s >> j & 1) continue;
                f[s | (1 << j)][j] = min(f[s | (1 << j)][j], f[s][i] + w[i][j]);
            }
        }
    }

    printf("%d\n", f[(1 << n) - 1][n - 1]);

    return 0;
}
