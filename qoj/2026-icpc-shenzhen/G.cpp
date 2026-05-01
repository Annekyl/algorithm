#include <iostream>
#include <vector>

using namespace std;

void solve() {
    long long a, b, n, s;
    cin >> a >> b >> n >> s;

    // 始终保持 a < b 方便后续分类讨论，集合 {a, b} 是无序的，可以直接交换
    if (a > b) swap(a, b);

    // 情况 1: s 不是 a 的倍数
    if (s % a != 0) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) cout << a << " ";
        cout << "\n";
        return;
    }

    // 情况 2: s 不是 b 的倍数
    if (s % b != 0) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) cout << b << " ";
        cout << "\n";
        return;
    }

    // 以下情况 s 既是 a 的倍数也是 b 的倍数
    
    // 特判: 如果 s 刚好等于最大的可用数字 b，那 b 绝对不能用
    if (s == b) {
        if (n < s / a) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) cout << a << " ";
            cout << "\n";
        } else {
            cout << "NO\n";
        }
        return;
    }

    // 情况 3: b 不是 a 的倍数
    // 循环块: (s/a - 1) 个 a, 然后 1 个 b
    if (b % a != 0) {
        cout << "YES\n";
        long long X = s / a;
        for (int i = 0; i < n; ++i) {
            if (i % X < X - 1) cout << a << " ";
            else cout << b << " ";
        }
        cout << "\n";
        return;
    }

    // 情况 4: b 是 a 的倍数，令 b = m * a
    long long m = b / a;
    
    // 死局情况: m == 2
    if (m == 2) {
        if (n < s / a) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) cout << a << " ";
            cout << "\n";
        } else {
            cout << "NO\n";
        }
        return;
    }

    // 绝处逢生: m >= 3
    // 循环块: 1 个 a，然后 (s/b - 1) 个 b
    if (m >= 3) {
        cout << "YES\n";
        long long Y = s / b;
        for (int i = 0; i < n; ++i) {
            if (i % Y == 0) cout << a << " ";
            else cout << b << " ";
        }
        cout << "\n";
        return;
    }
}

int main() {
    // 优化 I/O 速度，应对大规模读写
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}