/*
 * @lc app=leetcode.cn id=2312 lang=cpp
 * @lcpr version=30119
 *
 * [2312] 卖木头块
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
  long long sellingWood(int m, int n, vector<vector<int>> &prices) {
    typedef long long ll;
    vector<vector<int>> p(m + 1, vector<int>(n + 1, 0));
    for (auto &price : prices) {
      p[price[0]][price[1]] = price[2];
    }
    vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, -1));
    function<void(int, int)> dfs = [&](int x, int y) {
      if (dp[x][y] != -1) return;
      dp[x][y] = p[x][y];
      for (int i = x; i > 0; i--) {
        dfs(i, y);
        dfs(x - i, y);
        dp[x][y] = max(dp[x][y], dp[i][y] + dp[x - i][y]);
      }
      for (int i = y; i > 0; i--) {
        dfs(x, i);
        dfs(x, y - i);
        dp[x][y] = max(dp[x][y], dp[x][i] + dp[x][y - i]);
      }
    };
    dfs(m, n);
    return dp[m][n];
  }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n5\n[[1,4,2],[2,2,7],[2,1,3]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n6\n[[3,2,10],[1,4,2],[4,1,3]]\n
// @lcpr case=end

 */
