#include <bits/stdc++.h>

using namespace std;

// 存储所有回合数的分界点
vector<uint64_t> boundaries;

void precompute() {
    vector<uint64_t> power_2;
    vector<uint64_t> power_3;
    
    // 1. 生成 2 的次幂 (y_2)
    for (uint64_t p = 1; p <= 2e18; p *= 2) {
        power_2.push_back(p);
    }
    
    // 2. 生成 2^a * 3^b (b >= 1) 的数 (y_3)
    for (uint64_t p3 = 3; ; ) {
        for (uint64_t p = p3; ; ) {
            power_3.push_back(p);
            if (p > 2000000000000000000ULL / 2) break;
            p *= 2;
        }
        if (p3 > 2000000000000000000ULL / 3) break;
        p3 *= 3;
    }
    sort(power_3.begin(), power_3.end());
    
    // 3. 递推生成分界点 B_k
    boundaries.push_back(1); // f(1) = 0
    uint64_t curr_b = 2;     // f(2) = 1
    boundaries.push_back(curr_b);
    
    while (curr_b <= 1000000000000000000ULL) {
        // 在合法集合中找最小的 y >= curr_b
        uint64_t y2 = *lower_bound(power_2.begin(), power_2.end(), curr_b);
        uint64_t y3 = *lower_bound(power_3.begin(), power_3.end(), curr_b);
        
        // 计算相应的 Cost 代价
        uint64_t cost2 = y2 + 1;
        // 使用 y3 + y3 / 2 避免先乘 3 导致的 uint64_t 溢出风险，完全等价于 floor(1.5 * y3)
        uint64_t cost3 = y3 + y3 / 2 + 1; 
        
        uint64_t next_b = min(cost2, cost3);
        boundaries.push_back(next_b);
        curr_b = next_b;
    }
}

void solve() {
    uint64_t n;
    if (!(cin >> n)) return;
    
    // 通过二分查找计算落在哪个区间
    auto it = upper_bound(boundaries.begin(), boundaries.end(), n);
    int rounds = distance(boundaries.begin(), it) - 1;
    
    cout << rounds << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    
    // 如果有多组输入，这里可以加 while(cin >> n) 或 while(t--)
    solve(); 
    
    return 0;
}