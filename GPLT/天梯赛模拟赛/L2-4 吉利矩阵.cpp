#include "bits/stdc++.h"
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

const int N = 10;
int l, n;
int g[N][N];
int ans = 0;

void dfs(int x, int y) {
    int nx = (x + 1 <= n ? x + 1 : 1);
    int ny = (x == n ? ny + 1 : ny);

    // 最后一行的最后一列
    if(x==l&&y==l){
        for(int i=1;i<l;i++){
            
        }
    }

    // 最后一行
    if()

    // 最后一列

}

signed main() {
    cin >> l >> n;

    return 0;
}