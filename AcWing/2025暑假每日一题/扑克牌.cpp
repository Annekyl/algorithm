#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e3 + 10;

int n;
int arr[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(arr, 0, sizeof arr);
    cin >> n;
    // scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) {
        char a, b;
        int a1, b1;
        cin >> a >> b; // 使用cin避免读取换行符
        // scanf("%c %c\n", &a, &b);
        if (a == 'D')
            a1 = 0;
        else if (a == 'C')
            a1 = 1;
        else if (a == 'H')
            a1 = 2;
        else if (a == 'S')
            a1 = 3;

        if (b == 'A')
            b1 = 1;
        else if (b == 'T')
            b1 = 10;
        else if (b == 'J')
            b1 = 11;
        else if (b == 'Q')
            b1 = 12;
        else if (b == 'K')
            b1 = 13;
        else
            b1 = b - '0';
        arr[a1][b1]++;
    }

    int ans = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) {
            if (arr[i][j] == 0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}