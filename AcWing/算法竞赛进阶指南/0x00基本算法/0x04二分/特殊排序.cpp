#include "bits/stdc++.h"

using namespace std;

// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

class Solution {
  public:
    vector<int> specialSort(int N) {
        vector<int> ans;
        ans.push_back(1);
        for (int i = 2; i <= N; i++) {
            int l = 0, r = ans.size();
            while (l < r) {
                int mid = (r + l - 1) / 2;
                if (compare(ans[mid], i)) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            ans.insert(ans.begin() + l, i);
        }
        return ans;
    }
};