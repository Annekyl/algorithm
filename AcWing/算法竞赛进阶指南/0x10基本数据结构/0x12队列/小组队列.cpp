#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1010;

int t;
queue<int> q[N];
unordered_map<int, int> rec;
bool in_q[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 1;
    while (cin >> t, t) {
        cout << "Scenario #" << num << endl;

        // 清空全局变量
        memset(in_q, 0, sizeof in_q);
        rec.clear();
        for (int i = 0; i < N; i++) {
            while (!q[i].empty()) {
                q[i].pop();
            }
        }

        for (int i = 1; i <= t; i++) {
            int n;
            cin >> n;
            while (n--) {
                int x;
                cin >> x;
                rec[x] = i; // 插入到map中
                // rec.insert(make_pair(x, i));
            }
        }
        while (1) {
            string s;
            cin >> s;
            if (s == "STOP") {
                break;
            } else if (s == "ENQUEUE") {
                int x;
                cin >> x;
                // if (rec.find(x) != rec.end()) {
                    auto idx = rec.find(x)->second;
                    q[idx].push(x);
                    if (!in_q[idx]) {
                        q[0].push(idx);
                        in_q[idx] = true;
                    }
                // }
            } else if (s == "DEQUEUE") {
                // if (q[0].empty()) {
                    // continue;
                // }
                auto idx = q[0].front();
                cout << q[idx].front() << endl;
                q[idx].pop();
                if (q[idx].empty()) {
                    q[0].pop();
                    in_q[idx] = false;
                }
            }
        }
        num++;
        cout << endl;
    }

    return 0;
}