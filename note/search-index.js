// Auto-generated search index for ACM Algorithm Notes
const SEARCH_INDEX = [
  // 01 基础篇
  { title: "二分查找", url: "01-basic/binary-search.html", cat: "基础", keywords: "binary search 二分答案 浮点二分 整数二分 lower_bound upper_bound 二分查找 旋转数组" },
  { title: "前缀和与差分", url: "01-basic/prefix-sum.html", cat: "基础", keywords: "prefix sum difference array 前缀和 差分 二维前缀和 区间修改 区间求和" },
  { title: "贪心", url: "01-basic/greedy.html", cat: "基础", keywords: "greedy 贪心 区间调度 哈夫曼 分数背包 活动选择 区间覆盖" },
  { title: "分治", url: "01-basic/divide-conquer.html", cat: "基础", keywords: "divide conquer 归并排序 逆序对 快速排序 第k大 最近点对" },
  { title: "位运算", url: "01-basic/bit.html", cat: "基础", keywords: "bit manipulation 位运算 lowbit 状态压缩 枚举子集 popcount 异或" },
  { title: "STL 速查", url: "01-basic/stl.html", cat: "基础", keywords: "STL vector map set priority_queue sort lower_bound 容器 算法 pair deque" },

  // 02 搜索篇
  { title: "DFS 深度优先搜索", url: "02-search/dfs.html", cat: "搜索", keywords: "DFS 深度优先 连通块 剪枝 flood fill 搜索 栈 DFS序" },
  { title: "BFS 广度优先搜索", url: "02-search/bfs.html", cat: "搜索", keywords: "BFS 广度优先 最短路 多源BFS 0-1 BFS 双端队列 状态搜索" },
  { title: "迭代加深与IDA*", url: "02-search/idastar.html", cat: "搜索", keywords: "IDA* 迭代加深 启发式搜索 IDS 15数码 启发函数" },
  { title: "回溯法", url: "02-search/backtracking.html", cat: "搜索", keywords: "backtracking 回溯 全排列 N皇后 子集枚举 组合 数独" },

  // 03 DP篇
  { title: "线性 DP", url: "03-dp/linear-dp.html", cat: "DP", keywords: "线性DP LIS LCS 编辑距离 最长递增子序列 最长公共子序列 数字三角形" },
  { title: "背包问题", url: "03-dp/knapsack.html", cat: "DP", keywords: "knapsack 背包 01背包 完全背包 多重背包 分组背包 混合背包 方案数" },
  { title: "区间 DP", url: "03-dp/interval-dp.html", cat: "DP", keywords: "区间DP 石子合并 矩阵链乘 括号匹配 戳气球 环形区间" },
  { title: "树形 DP", url: "03-dp/tree-dp.html", cat: "DP", keywords: "树形DP 树的直径 树的重心 最大独立集 树上背包 换根DP rerooting" },
  { title: "数位 DP", url: "03-dp/digit-dp.html", cat: "DP", keywords: "数位DP digit DP 记忆化搜索 tight 数字计数 不含某数字" },
  { title: "状态压缩 DP", url: "03-dp/bitmask-dp.html", cat: "DP", keywords: "状压DP bitmask 状态压缩 TSP 旅行商 棋盘覆盖 集合划分 Hamilton" },
  { title: "DP 优化", url: "03-dp/dp-opt.html", cat: "DP", keywords: "DP优化 单调队列优化 斜率优化 凸壳 trick 四边形不等式 决策单调" },

  // 04 图论篇
  { title: "图的存储", url: "04-graph/graph-rep.html", cat: "图论", keywords: "邻接矩阵 邻接表 链式前向星 图存储 edge" },
  { title: "最短路", url: "04-graph/shortest-path.html", cat: "图论", keywords: "最短路 Dijkstra SPFA Floyd Bellman-Ford Johnson 负权边 最短路径" },
  { title: "最小生成树", url: "04-graph/mst.html", cat: "图论", keywords: "MST 最小生成树 Kruskal Prim Boruvka 次小生成树" },
  { title: "拓扑排序", url: "04-graph/topo-sort.html", cat: "图论", keywords: "topological sort 拓扑排序 Kahn DAG 判环 入度 最长路" },
  { title: "强连通分量", url: "04-graph/scc.html", cat: "图论", keywords: "SCC 强连通 Tarjan Kosaraju 缩点 2-SAT DAG" },
  { title: "二分图", url: "04-graph/bipartite.html", cat: "图论", keywords: "二分图 匈牙利算法 最大匹配 最小点覆盖 König 匈牙利 KM 匹配" },
  { title: "网络流", url: "04-graph/network-flow.html", cat: "图论", keywords: "网络流 最大流 Dinic 最小割 费用流 MCMF Edmonds-Karp 增广路" },
  { title: "最近公共祖先", url: "04-graph/lca.html", cat: "图论", keywords: "LCA 最近公共祖先 倍增 Tarjan离线 树上距离" },
  { title: "欧拉路径", url: "04-graph/euler.html", cat: "图论", keywords: "欧拉路径 欧拉回路 Hierholzer 一笔画 度数" },

  // 05 字符串篇
  { title: "KMP 算法", url: "05-string/kmp.html", cat: "字符串", keywords: "KMP next数组 字符串匹配 模式匹配 周期" },
  { title: "字符串哈希", url: "05-string/hash.html", cat: "字符串", keywords: "字符串哈希 hash 滚动哈希 双哈希 子串 回文判" },
  { title: "Trie 树", url: "05-string/trie.html", cat: "字符串", keywords: "Trie 字典树 前缀树 01-Trie 最大异或对 可持久化" },
  { title: "AC 自动机", url: "05-string/ac-automaton.html", cat: "字符串", keywords: "AC自动机 多模式匹配 fail树 自动机 Trie图" },
  { title: "后缀数组", url: "05-string/suffix-array.html", cat: "字符串", keywords: "后缀数组 SA LCP 本质不同子串 倍增 后缀 rank" },
  { title: "Manacher 算法", url: "05-string/manacher.html", cat: "字符串", keywords: "Manacher 回文 最长回文子串 回文半径 回文串" },

  // 06 数据结构篇
  { title: "并查集", url: "06-ds/union-find.html", cat: "数据结构", keywords: "并查集 DSU 路径压缩 按秩合并 带权并查集 种类并查集" },
  { title: "线段树", url: "06-ds/segment-tree.html", cat: "数据结构", keywords: "线段树 segment tree 懒标记 区间修改 动态开点 合并" },
  { title: "树状数组", url: "06-ds/bit-fenwick.html", cat: "数据结构", keywords: "树状数组 BIT Fenwick 逆序对 lowbit 区间修改 二维" },
  { title: "ST 表", url: "06-ds/st-table.html", cat: "数据结构", keywords: "ST表 稀疏表 sparse table RMQ 区间最值 O(1)查询" },
  { title: "单调栈", url: "06-ds/monotone-stack.html", cat: "数据结构", keywords: "单调栈 下一个更大元素 柱状图最大矩形 接雨水" },
  { title: "单调队列", url: "06-ds/monotone-queue.html", cat: "数据结构", keywords: "单调队列 滑动窗口最值 deque DP优化" },
  { title: "可持久化数据结构", url: "06-ds/persistent.html", cat: "数据结构", keywords: "可持久化 主席树 persistent segment tree 区间第k小 版本" },

  // 07 数学篇
  { title: "素数", url: "07-math/prime.html", cat: "数学", keywords: "素数 质数 埃氏筛 欧拉筛 线性筛 Miller-Rabin 素性测试 分解" },
  { title: "GCD与扩展欧几里得", url: "07-math/gcd.html", cat: "数学", keywords: "GCD 扩展欧几里得 exGCD 裴蜀定理 模逆元 中国剩余定理 CRT 线性求逆" },
  { title: "组合数学", url: "07-math/combinatorics.html", cat: "数学", keywords: "组合数 C(n,k) Lucas 卡特兰数 容斥原理 阶乘逆元 排列" },
  { title: "矩阵快速幂", url: "07-math/matrix.html", cat: "数学", keywords: "矩阵 矩阵乘法 快速幂 Fibonacci 递推 线性递推" },
  { title: "博弈论", url: "07-math/sg.html", cat: "数学", keywords: "博弈论 Nim SG函数 巴什博弈 威佐夫 mex Anti-Nim 博弈" },
  { title: "高斯消元", url: "07-math/gauss.html", cat: "数学", keywords: "高斯消元 线性方程组 异或方程组 行列式 矩阵求逆" },
  { title: "FFT / NTT", url: "07-math/fft.html", cat: "数学", keywords: "FFT NTT 多项式乘法 快速傅里叶变换 蝴蝶运算 卷积" },

  // 08 计算几何篇
  { title: "基础计算几何", url: "08-geometry/basic-geo.html", cat: "几何", keywords: "计算几何 向量 点积 叉积 直线交点 多边形面积 叉积 方向" },
  { title: "凸包", url: "08-geometry/convex-hull.html", cat: "几何", keywords: "凸包 Andrew Graham 旋转卡壳 convex hull 直径" },

  // 09 杂项篇
  { title: "双指针", url: "09-misc/two-pointer.html", cat: "杂项", keywords: "双指针 滑动窗口 对撞指针 快慢指针 two pointer 单调性" },
  { title: "莫队算法", url: "09-misc/mo.html", cat: "杂项", keywords: "莫队 带修莫队 回滚莫队 分块 离线查询 sqrt" },
  { title: "常用技巧", url: "09-misc/tricks.html", cat: "杂项", keywords: "离散化 读入优化 对拍 模拟退火 卡常 pragma 快速IO" },
];
