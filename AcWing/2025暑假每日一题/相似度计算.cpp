#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1e4 + 10;

int n, m;
set<string> s1;
set<string> sum_s;   // 存两者全部的单词
set<string> total_s; // 存两者共有的单词
int cnt;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    // cout << (int)'a' << " " << (int)'A';    // 相差32 a:97 A:65
    for (int i = 1; i <= n; i++) {
        cin >> s;
        // 全部转换成大写来存
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a') {
                s[i] -= 32;
            }
        }
        s1.insert(s);
        sum_s.insert(s);
    }
    for (int i = 1; i <= m; i++) {
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a') {
                s[i] -= 32;
            }
        }
        sum_s.insert(s);
        if (s1.find(s) != s1.end()) {
            total_s.insert(s);
        }
    }
    cout << total_s.size() << endl;
    cout << sum_s.size() << endl;
    return 0;
}