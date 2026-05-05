#include "bits/stdc++.h"

using namespace std;

class MinStack {
  private:
    vector<int> a;
    vector<int> min_val;

  public:
    /** initialize your data structure here. */
    MinStack() { min_val.push_back(0x3f3f3f3f); }

    void push(int x) {
        a.push_back(x);
        min_val.push_back(min(min_val.back(), x));
    }

    // 如果弹出的是最小的元素，需要对最小的元素进行更新
    void pop() {
        a.pop_back();
        min_val.pop_back();
    }

    int top() { return a.back(); }

    int getMin() { return min_val.back(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */