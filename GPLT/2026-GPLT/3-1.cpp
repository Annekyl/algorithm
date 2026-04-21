#include "bits/stdc++.h"
#define int long long
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

typedef pair<int, int> pii;

struct People {
    int st, order;
    string id;
    int age;
};

signed main() {
    int n;
    cin >> n;
    People a[n];
    for (int i = 0; i < n; i++) {
        int st, order, age;
        string id;
        cin >> st >> order >> id >> age;
        a[i] = {st, order, id, age};
    }

    vector<int> q; // 存a对应的下标
    int pos = 0;
    for (int cycle = 1; cycle <= n || q.size(); cycle++) {
        // 处理新来的患者
        while (pos < n && a[pos].st == cycle) {
            q.push_back(pos);
            pos++;
        }
        if (q.size() == 0)
            continue;

        int choose = -1; // 当前处理患者对应a的下标
        int temp;        // 当前处理的患者对应q的下标

        // 先找有没有这个编号的患者还没有处理
        for (int i = 0; i < q.size(); i++) {
            int idx = q[i];
            if (a[idx].order == cycle) {
                choose = idx;
                temp = i;
                break;
            }
        }

        // 如果没有，找年龄大于等于80的患者中编号最小的
        if (choose == -1) {
            for (int i = 0; i < q.size(); i++) {
                int idx = q[i];
                if (a[idx].age >= 80) {
                    if (choose == -1) {
                        choose = idx;
                        temp = i;
                    } else {
                        choose =
                            (a[choose].order < a[idx].order ? choose : idx);
                        temp = (a[choose].order < a[idx].order ? temp : i);
                    }
                }
            }
        }

        // 还是没有，找已经来了的预约号最小的
        if (choose == -1) {
            for (int i = 0; i < q.size(); i++) {
                int idx = q[i];
                if (choose == -1 || a[idx].order < a[choose].order) {
                    choose = idx;
                    temp = i;
                }
            }
        }

        q.erase(q.begin() + temp);

        cout << cycle << " " << a[choose].id << endl;
    }

    return 0;
}
