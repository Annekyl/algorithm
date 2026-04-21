#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

const int N = 35;
int n;
int in[N], post[N];

struct Node {
    int val;
    Node *l;
    Node *r;
};

Node *build(int in_st, int in_ed, int post_st, int post_ed) {
    if (in_st > in_ed)
        return nullptr;

    Node *root = new Node{post[post_ed], nullptr, nullptr};

    int pos = in_st; // ⚠️当前子树的根在中序序列的下标
    while (in[pos] != root->val)
        pos++;
    int len = pos - in_st;
    root->l = build(in_st, pos - 1, post_st, post_st + len - 1);
    root->r = build(pos + 1, in_ed, post_st + len, post_ed - 1);
    return root;
}

void solve() {
    cin >> n;
    // cout << n << endl;
    for (int i = 1; i <= n; i++) {
        cin >> post[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> in[i];
    }

    Node *root = build(1, n, 1, n);
    // cout << 1 << endl;
    queue<pair<Node *, int>> q;
    q.push({root, 1});
    bool suc = true;
    while (q.size()) {
        auto [node, level] = q.front();
        q.pop();
        if (node->val % level != 0)
            suc = false;
        if (node->l != nullptr) {
            q.push({node->l, level + 1});
        }
        if (node->r != nullptr) {
            q.push({node->r, level + 1});
        }
    }
    if (!suc) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
}

signed main() {
    int m;
    cin >> m;
    // cout << m << endl;
    while (m--)
        solve();

    return 0;
}