#include "bits/stdc++.h"
#define int long long
#define debug(x) cout << #x <<" = " << x << endl

using namespace std;

signed main(){
    int n;
    cin>>n;
    int ans=0;
    while(n--){
        int x;
        cin>>x;
        if(x<1700)ans++;
    }
    cout<<ans<<endl;
    return 0;
}
