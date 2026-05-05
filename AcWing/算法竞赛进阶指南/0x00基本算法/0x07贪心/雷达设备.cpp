#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 1010;

int n, d;
vector<pdd> qujian;

pdd get_qujian(int x, int y) {
    double dx = sqrt(d * d - y * y);
    return make_pair(x - dx, x + dx);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool flag = true; // 标记是否存在可行的解决方案
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        if (y > d) {
            flag = false;
        }
        if (flag)
            qujian.push_back(get_qujian(x, y));
    }
    if (!flag) {
        cout << -1;
        return 0;
    }
    sort(qujian.begin(), qujian.end());
    // for (auto q : qujian) {
    // cout << q.first << " " << q.second << endl;
    // }

    int cnt = 0;
    double pos = -INF;
    for (auto &[l, r] : qujian) {
        if (pos == -INF || l > pos) {
            cnt++;
            pos = r;
            // cout << "cnt:" << cnt << endl;
            // cout << "l:" << l << endl;
            // cout << "pos:" << pos << endl;
        } else {
            pos = min(pos, r);
        }
    }

    cout << cnt;
    return 0;
}