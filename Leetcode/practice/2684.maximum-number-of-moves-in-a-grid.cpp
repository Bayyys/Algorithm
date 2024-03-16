/*
 * @lc app=leetcode.cn id=2684 lang=cpp
 * @lcpr version=30119
 *
 * [2684] 矩阵中移动的最大次数
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
  int maxMoves(vector<vector<int>> &grid) {
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
    int dist[3][2] = {{-1, 1}, {0, 1}, {1, 1}};
    int max_moves = 0;
    auto dfs = [&](auto &&self, int x, int y) -> int {
      if (dp[x][y] != -1) return dp[x][y];
      int max_move = 0;
      for (int i = 0; i < 3; i++) {
        int nx = x + dist[i][0];
        int ny = y + dist[i][1];
        if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) {
          continue;
        }
        if (grid[nx][ny] > grid[x][y]) {
          max_move = max(max_move, self(self, nx, ny));
        }
      }
      dp[x][y] = max_move + 1;
      return dp[x][y];
    };
    for (int i = 0; i < grid.size(); i++) {
      max_moves = max(max_moves, dfs(dfs, i, 0));
    }
    return max_moves - 1;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,2,4],[2,1,9],[1,1,7]]\n
// @lcpr case=end

 */
