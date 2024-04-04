/*
 * @lc app=leetcode.cn id=2192 lang=cpp
 * @lcpr version=30121
 *
 * [2192] 有向无环图中一个节点的所有祖先
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// @lcpr-template-end
// @lc code=start
class Solution {
 public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
    vector<unordered_set<int>> ans(n);  // 存储每个节点祖先的辅助数组
    vector<vector<int>> path(n);           // 邻接表
    vector<int> indegee(n);               // 入度表
    // 预处理
    for (const auto &edge : edges) {
      path[edge[0]].push_back(edge[1]);
      ++indegee[edge[1]];
    }
    // 广度优先搜索求解拓扑排序
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (!indegee[i]) {
        q.push(i);
      }
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : path[u]) {
        // 更新子节点的祖先哈希表
        ans[v].insert(u);
        for (int i : ans[u]) {
          ans[v].insert(i);
        }
        --indegee[v];
        if (!indegee[v]) {
          q.push(v);
        }
      }
    }
    // 转化为答案数组
    vector<vector<int>> res(n);
    for (int i = 0; i < n; ++i) {
      for (int j : ans[i]) {
        res[i].push_back(j);
      }
      sort(res[i].begin(), res[i].end());
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 8\n[[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]\n
// @lcpr case=end

 */
