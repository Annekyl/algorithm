#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;
typedef pair<LL, int> PII;
const int N = 100010;

int n;
int l[N], r[N];
int p[N];
PII a[N], ans[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n);

    a[0].first = -10e9, a[n + 1].first = 10e9;
    for (int i = 1; i <= n; i++) {
        l[i] = i - 1, r[i] = i + 1;
        p[a[i].second] = i;
    }

    for (int i = n; i > 1; i--) {
        int j = p[i], left = l[j], right = r[j];
        LL left_value = abs(a[left].first - a[j].first);
        LL right_value = abs(a[right].first - a[j].first);
        if (left_value <= right_value)
            ans[i] = {left_value, a[left].second};
        else
            ans[i] = {right_value, a[right].second};
        l[right] = left, r[left] = right;
    }

    for (int i = 2; i <= n; i++)
        cout << ans[i].first << ' ' << ans[i].second << endl;

    return 0;
}
