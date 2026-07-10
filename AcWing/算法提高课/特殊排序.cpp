// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.
#include "bits/stdc++.h"

using namespace std;

class Solution {
  public:
    vector<int> specialSort(int N) {
        vector<int> a;
        a.push_back(1);
        for (int i = 2; i <= N; i++) {
            int l = 0, r = a.size() - 1;
            while (l <= r) {
                int mid = l + r >> 1;
                if (compare(i, a[mid])) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            a.insert(a.begin() + l, i);
        }
        return a;
    }
};