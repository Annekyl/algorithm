#include "bits/stdc++.h"
#define int long long
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

signed main() {
    int n;
    cin >> n;
    set<int> st;
    set<int> no;
    while (n--) {
        int id, rec;
        cin >> id >> rec;
        if (rec == 0) {
            if (no.find(id) != no.end())
                continue;
            st.insert(id);
        } else {
            if (st.find(id) != st.end()) {
                st.erase(id);
            }
            no.insert(id);
        }
    }
    if (st.size() == 0) {
        cout << "NONE";
        return 0;
    }
    bool first = true;
    for (auto i = st.begin(); i != st.end(); i++) {
        if (!first)
            cout << " ";
        cout << *i;
        first = false;
    }
    return 0;
}
